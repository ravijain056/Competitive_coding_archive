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
    x %= mod;
    y %= mod-1;
    while(y > 0) {
        if(y & 1) res = (res * x) % mod;
        y >>= 1;
        x = (x*x) % mod;
    }
    return res;
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
        ll n;
        cin >> n;
        ll ans = 0;
        if(n == 4) ans = powmod(16, 4);
        else if(n == 5) 
            ans = ((2 + 2 * 4 * 4 + 6 * 6) * powmod(16, 3)) % mod;
        else if(n == 6) 
            ans = ((2 + 2 * 4 * 4 + 6 * 6) * 16 * 16 * (2 + 2 * 4 * 4 + 6 * 6)) % mod;
        else if(n == 7)
            ans = (powmod(2 + 2 * 4 * 4 + 6 * 6, 3) * 16) % mod;
        else {
            ans = powmod(2 + 2 * powmod(4, n/4) + powmod(6, n/4), 4 - (n % 4));
            ans *= powmod(2 + 2 * powmod(4, (n/4)+1) + powmod(6, (n/4)+1), n % 4);
            ans %= mod;
        }
        cout << ans << "\n";
    }

    return 0;
}
