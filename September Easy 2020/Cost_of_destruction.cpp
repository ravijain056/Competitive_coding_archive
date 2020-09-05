#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<bool> vb;
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

const ll mod = 1e9+7;

vl fac, inv;

ll modinv(ll x) {
    ll y = mod-2;
    ll res = 1;
    while(y) {
        if(y&1) res = (res * x) % mod;
        y >>= 1;
        x = (x*x) % mod;
    }
    return res;
}

ll nCr(ll n, ll r) {
    return (((fac[n] * inv[r]) % mod) * inv[n-r]) % mod;
}

int main() {

    #ifdef LOCAL_DEV
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    fac.resize(n+10);
    inv.resize(n+10);

    fac[0] = 1;
    inv[0] = 1;
    for(ll i = 1; i < n + 10; i++) {
        fac[i] = (fac[i-1] * i) % mod;
        inv[i] = modinv(fac[i]);
    }
    
    ll ans = 0, x, y;
    if(n&1) {
        x = (n-1)/2, y = x-1;
    } else {
        x = (n-2)/2, y = x;
    }
    ll prev = 0;
    while(y >= 0) {
        ll cur = (((nCr(x, y) * fac[x+1]) % mod) * fac[n-x-2]) % mod;
        ans += (((cur-prev + mod) % mod) * (x+1)) % mod;
        ans %= mod;
        prev = cur;
        x++; y--;
    }

    cout << ans;
    return 0;
}