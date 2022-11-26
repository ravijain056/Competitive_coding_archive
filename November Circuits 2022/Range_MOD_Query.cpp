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
    if(y < 0) y += mod-1;
    while(y > 0) {
        if(y & 1) res = (res * x) % mod;
        y >>= 1;
        x = (x*x) % mod;
    }
    return res;
}

vl t;
int n;

void build() {
    for(int i = n-1; i > 0; --i) t[i] = (t[i<<1] + t[i << 1|1]) % mod;
}

void update(int i, ll val) {
    for(t[i += n] = val; i > 1; i >>= 1) t[i>>1] = (t[i] + t[i^1]) % mod;
}

ll query(int l, int r) {
    ll res = 0;
    for(l+=n, r+=n; l < r; l >>= 1, r >>= 1) {
        if(l&1) res += t[l++];
        if(r&1) res += t[--r];
        res %= mod;
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

    int q;
    cin >> n >> q;

    string bits;
    cin >>bits;

    t.assign(2*n, 0);

    for(int i = 0; i < n; i++) 
        if(bits[i] == '1') t[i+n] = powmod(2, n-i-1);
    build();

    while(q--) {
        int t;
        cin >> t;
        if(t == 1) {
            int i;
            cin >> i;
            i--;
            if(bits[i] == '0') {
                bits[i] = '1';
                update(i, powmod(2, n-i-1));
            } else {
                bits[i] = '0';
                update(i, 0);
            }
        } else {
            int l, r;
            cin >> l >> r;
            ll ans = query(l-1, r);
            ans *= powmod(2, - n + r);
            ans %= mod;
            cout << ans << "\n";
        }
    }


    return 0;
}
