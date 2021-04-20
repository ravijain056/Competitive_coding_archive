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



int main() {

    #ifdef LOCAL_DEV
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for(int ti = 1; ti <= t; ti++) {
        int m;
        cin >> m;

        unordered_map<ll, ll> prime_cnts;

        ll total = 0;

        vl primes;

        for(int i = 0; i < m; i++) {
            ll p, n;
            cin >> p >> n;
            prime_cnts[p] = n;
            total += n * p;
            primes.pb(p);
        }
        
        ll score = 0;

        for(ll i = 1; i < 29940; i++) {
            ll cur = total - i;
            if(cur < 2) break;
            unordered_map<ll, ll> rem;

            for(auto pc : prime_cnts) {
                ll n = 0;
                ll p = pc.first, c = pc.second;
                while(cur % p == 0) {
                    cur /= p;
                    n++;
                    if(n > c) break;
                }
                if(n > c) break;
                rem[p] = c - n;
            }
            if(cur != 1) continue;
            ll lsum = 0;
            for(auto pc : rem) {
                lsum += pc.first * pc.second;
            }
            if(lsum == total - i) {
                score = lsum;
                break;
            }
        }

        cout << "Case #" << ti << ": " << score << "\n"; 
    }

    return 0;
}
