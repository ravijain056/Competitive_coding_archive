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
        int n, x, y;
        cin >> n >> x >> y;

        if(y <= n) {
            for(int i = 1; i <= n; i++) cout << i << " ";
            cout << "\n";
        } else if(y-x < n){
            int start = max(1, y-n+1);
            for(int i = 1; i <= n; i++) cout << start++ << " ";
            cout << "\n";
        } else {
            int diff = y-x;
            for(int dist = n-1; dist >= 1; dist--) {
                if(diff % dist == 0) {
                    int d = diff/dist;
                    int start = max(y % d, y - (n-1) * d);
                    while(start <= 0) start += d;
                    for(int i = 1; i <= n; i++, start+=d) cout << start << " ";
                    cout << "\n";
                    break;
                }
            }
        }
        
        //cout << "Case #" << ti << ": " ; 
    }

    return 0;
}