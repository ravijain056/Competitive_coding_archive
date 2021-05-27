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
    cout << setprecision(6) << fixed;

    int t;
    cin >> t;

    for(int ti = 1; ti <= t; ti++) {
        
        ll g;
        cin >> g;

        int ans = 1;
        
        for(ll n = 2; n * n <= 2 * g; n++) {
            ll calc = 2 * g - n * n; 
            if(calc % n == 0) {
                calc = (calc / n) + 1;
                if(calc % 2 == 0) ans ++;
            }
        } 

        cout << "Case #" << ti << ": " << ans << "\n"; 
    }

    return 0;
}
