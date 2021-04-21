#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<bool> vb;
typedef vector<ll> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define mp make_pair
#define pb push_back

const ll mod = 1e9+7;

ll n, k;
double m;
vi A;
unordered_map<ll, double> dp;

ll getid(vi& B) {
    ll ret = 0, mul = 1;
    for(ll i = 0; i < k; i++) {
        ret += B[i] * mul;
        mul *= (A[i]+1);
    }
    return ret;
}

double get(vi cur, ll roll) {
    ll id = getid(cur);
    if(dp.find(id) != dp.end()) return dp[id];
    double z = 0;
    double x = 0;
    dp[id] = 1.0;
    vector<pair<double, double> > fracs;
    for(ll i = k-1; i >= 0; i--) {
        if(cur[i] == 0) {
            cur[i]++;
            fracs.pb(mp(m-x, (roll != n ? get(cur, roll+1) : 0)));
            z += (m-x);
            break;
        }
        x++;
        if(cur[i] < A[i]) {
            ll j = i;
            while(i > 0 && cur[i-1] == cur[j]) {
                i--;
                x++;
            }
            double cnt = j-i+1;
            cur[j]++;
            fracs.pb(mp(cnt, (roll != n ? get(cur, roll+1) : 0)));
            cur[j]--;
            z += cnt;
        }
    }

    vb include(fracs.size(), true);
    while(true) {
        dp[id] = m/z;
        for(int i = 0; i < fracs.size(); i++) {
            auto f = fracs[i];
            if(include[i]) dp[id] += (f.first / z) * f.second;
        }
        bool done = true;
        for(int i = 0; i < fracs.size(); i++) {
            auto f = fracs[i];
            if(include[i] && f.second > dp[id]) {
                z -= f.first;
                include[i] = false;                
                done = false;
            }
        }
        if(done) break;
    }
    
    return dp[id];
}

int main() {

    #ifdef LOCAL_DEV
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    cout << fixed << setprecision(6);

    for(ll ti = 1; ti <= t; ti++) {
        cin >> n >> m >> k;
        A.resize(k);
        dp.clear();
        for(ll i = 0; i < k; i++) cin >> A[i];
        
        cout << "Case #" << ti << ": " ; 
        cout << get(vi(k, 0), 1) << "\n";
    }

    return 0;
}