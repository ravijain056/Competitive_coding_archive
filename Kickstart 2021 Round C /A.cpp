#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define mp make_pair
#define pb push_back

const int mod = 1e9+7;

ll powmod(ll x, ll y) {
    ll res = 1;
    
    while(y > 0) {
        if(y & 1)
            res = (res * x) % mod;
        
        y >>= 1;
        x = (x*x) % mod;
    }
    return res;
}

ll brute(string s, int k, int pn, int n) {
    ll ans = 0;
    if(pn == 1) {
        string cmp = s;
        
        for(int i = 0; i < k; i++) {
            cmp[0] = 'a' + i;
            cmp[n-1] = 'a' + i;
            if(cmp <  s) ans++;
        }
        return ans;
    }
    if(pn == 2) {
        string cmp = s;
        
        for(int i = 0; i < k; i++) {
            cmp[0] = 'a' + i;
            cmp[n-1] = 'a' + i;
            for(int i1 = 0; i1 < k; i1++) {
                cmp[1] = 'a' + i1;
                cmp[n-1-1] = 'a' + i1;
                if(cmp <  s) ans++;
            }
        }
        return ans;
    }
    if(pn == 3) {
        string cmp = s;
        
        for(int i = 0; i < k; i++) {
            cmp[0] = 'a' + i;
            cmp[n-1] = 'a' + i;
            for(int i1 = 0; i1 < k; i1++) {
                cmp[1] = 'a' + i1;
                cmp[n-1-1] = 'a' + i1;
                for(int i2 = 0; i2 < k; i2++) {
                    cmp[2] = 'a' + i2;
                    cmp[n-2-1] = 'a' + i2;
                    if(cmp <  s) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
    if(pn == 4) {
        string cmp = s;
        
        for(int i = 0; i < k; i++) {
            cmp[0] = 'a' + i;
            cmp[n-1] = 'a' + i;
            for(int i1 = 0; i1 < k; i1++) {
                cmp[1] = 'a' + i1;
                cmp[n-1-1] = 'a' + i1;
                for(int i2 = 0; i2 < k; i2++) {
                    cmp[2] = 'a' + i2;
                    cmp[n-2-1] = 'a' + i2;
                    for(int i3 = 0; i3 < k; i3++) {
                        cmp[3] = 'a' + i3;
                        cmp[n-3-1] = 'a' + i3;
                        if(cmp <  s) ans++;
                    }
                }
            }
        }
        return ans;
    }
    return 0;
}

vector<string> cases;

void generate1(int n, int k, string s) {
    if(n == 0) {
        cases.pb(s);
        return;
    }
    for(int i = 0; i < k; i++) {
        s.pb('a' + i);
        generate1(n-1, k, s);
        s.pop_back();
    }
    return;
}   

int main() {

    #ifdef LOCAL_DEV
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(6) << fixed;

    int t;
    cin >> t;

    for(int ti = 1; ti <= t; ti++) {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        int pn = (n+1)/2;
        bool eq = true, greater = true;
        ll ans = 0;

        string cmp = s;
        for(int i = 0; i < pn; i++) {
            ans += (((s[i] - 'a') * powmod(k, pn-1-i)) % mod);
            ans %= mod;
            cmp[n-i-1] = s[i];
        }

        if(cmp < s) ans++;
        ans %= mod;

        //ll ans2 = brute(s, k, pn, n);
        //if(ans2 != ans) cout << s << " " << k << " " << ans << " " << ans2 << "\n";
        cout << "Case #" << ti << ": " << ans << "\n"; 
    }
    
    return 0;

    generate1(8, 5, "");
    cout << cases.size() << "\n";
    for(string s : cases) {
        cout << "8 5 \n";
        cout << s << "\n";
    }

    return 0;
}
