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
        int n, c;
        cin >> n >> c;
        int minC = n-1, maxC = (n*(n+1) / 2) - 1;
        if(c < minC || c > maxC) {
            cout << "Case #" << ti << ": IMPOSSIBLE\n" ;   
        } else {
            
            vi j(n-1, 1);
            int diff = c - (n-1);
            int maxadd = n-1;
            int i = 0;
            while(diff > 0) {
                if(diff >= maxadd) j[i] += maxadd;
                else j[i] += diff;
                diff -= maxadd;
                maxadd--;
                i++;
            }

            vi L(n);
            for(int i = 0; i < n; i++) L[i] = i+1;

            for(int i = n-2; i >= 0; i--) {
                reverse(L.begin() + i, L.begin() + i + j[i]);
            }
            
            cout << "Case #" << ti << ": " ; 
            for(int o : L) cout << o << " ";
            cout << "\n"; 
        }
    }

    return 0;
}
