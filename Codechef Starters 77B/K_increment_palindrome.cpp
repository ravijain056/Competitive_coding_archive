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

vb isPrime;
vl primes;

void fillPrimes(int n) {
    isPrime.assign(n + 1, true);
    for(ll i = 2; i <= n; i++) {
        if(isPrime[i]) primes.pb(i);
        for(ll j : primes) {
            if(i*j > n) break;
            isPrime[i*j] = false;
        }
    }
}

vl seg;
int seg_len;

void build_seg(vl A, int n) {
    seg.resize(2 * n);
    seg_len = n;
    for(int i = n ;  i < 2*n; i++) seg[i] = A[i-n];
    for(int i = n-1; i > 0; --i) seg[i] = (seg[i<<1] + seg[i << 1|1]) % mod;
}

void update_seg(int i, ll val) {
    int n = seg_len;
    for(seg[i += n] = val; i > 1; i >>= 1) seg[i>>1] = (seg[i] + seg[i^1]) % mod;
}

ll query_seg(int l, int r) {
    ll res = 0;
    int n = seg_len;
    for(l+=n, r+=n; l < r; l >>= 1, r >>= 1) {
        if(l&1) res += seg[l++];
        if(r&1) res += seg[--r];
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

    int t;
    cin >> t;

    for(int ti = 1; ti <= t; ti++) {
        int n, k;
        cin >> n >> k;
        vi A(n);
        for(int i = 0; i < n; i++) cin >> A[i];
        int i = 0, j = n-1;
        bool pal = true;
        while(i < j) {
            if(A[i++] != A[j--]) {
                pal = false;
                break;
            }
        }
        
        if(pal) {
            cout << "YES\n";
            continue;
        }
        
        if(k == n) {
            cout << "NO\n";
            continue;
        }
        
        if(n & 1 || k & 1) {
            cout << "YES\n";
            continue;
        }
        
        int totdiff = 0;
        i = 0, j = n-1;
        while(i < j) totdiff += abs(A[i++] - A[j--]);
        
        if(totdiff & 1) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}