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

vi primes;
vb isPrime(1e5 + 4, true);

void sieve() {
    for(ll i = 2; i < 1e5 + 4; i++) {
        if(isPrime[i]) {
            for(ll j = i *  i; j < 1e5 + 4; j += i) {
                isPrime[j] = false;
            }
            primes.pb(i);
        }
    }
}

bool checkPrime(ll x) {
    if(x < 1e5 + 4) return isPrime[x];
    ll sqx  = sqrt(x);
    for(int p : primes) {
        if(p > sqx) return true;
        if(x % p == 0) return false;
    }
    return true;
}

int main() {

    #ifdef LOCAL_DEV
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    sieve();

    for(int ti = 1; ti <= t; ti++) {
        ll z;
        cin >> z;

        ll sqz = sqrt(z);

        cout << "Case #" << ti << ": " ;

        ll ans;

        if(sqz < 1e5 + 3) {
            auto it = upper_bound(primes.begin(), primes.end(), sqz);
            ans = *it * (*(it - 1));
            if(ans > z) {
                it--;
                ans = *it * (*(it - 1));;
            }
        } else {
            ll upper = sqz+1;
            while(!checkPrime(upper)) upper++;
            ll lower = sqz;
            while(!checkPrime(lower)) lower--;
            ans = upper * lower;
            if(ans > z) {
                upper = lower;
                lower = upper - 1;
                while(!checkPrime(lower)) lower--;
                ans = upper * lower;
            }
        }

        cout << ans << "\n"; 
    }
    
   
    return 0;
}
