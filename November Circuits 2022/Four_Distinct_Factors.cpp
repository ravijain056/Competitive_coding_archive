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
vb isPrime(5e5 + 1, true);
vl primes;
vb isFav(1e6 + 1, false);
vi favCount(1e6 + 1, 0);

void fillPrimes() {
    for(ll i = 2; i <= 5e5; i++) {
        if(isPrime[i]) primes.pb(i);
        for(ll j : primes) {
            if(i*j > 5e5) break;
            isPrime[i*j] = false;
        }
    }
}

void checkFavs() {
    for(ll i : primes) {
        for(ll j : primes) {
            if(j == i || i*j > 1e6) break;
            isFav[i*j] = true;
        }
        if(i * i * i <= 1e6) isFav[i*i*i] = true;
    }
}

void countFavs() {
    for(int i = 1; i <= 1e6; i++) favCount[i] = favCount[i-1] + isFav[i];
}

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

    fillPrimes();
    checkFavs();
    countFavs();

    int t;
    cin >> t;

    for(int ti = 1; ti <= t; ti++) {
        int l, r;
        cin >> l >> r;
        cout << favCount[r] - favCount[l-1] << "\n";
        //cout << "Case #" << ti << ": " ; 
    }

    return 0;
}
