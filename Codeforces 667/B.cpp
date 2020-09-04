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
        ll a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;
        ll ans;
        if(a-n < x) {
            ans = x * max(y, a + b - n - x);
        } else {
            ans = (a-n) * b;
        }

        if(b-n < y) {
            ans = min(ans, y * max(x, a + b - n - y));
        } else {
            ans = min(ans, a * (b-n));
        }
         
        cout << ans << "\n";
        
        //cout << "Case #" << ti << ": " ; 
    }

    return 0;
}