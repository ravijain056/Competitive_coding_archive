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
        int r, c;
        cin >> r >> c;
        
        vvi grid(r, vi(c));

        vvb vis(r, vb(c, false));

        priority_queue<pair<int, pii> > bfs;

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                cin >> grid[i][j];
                bfs.push(mp(grid[i][j], mp(i, j)));
            }
        }

        ll count = 0;

        while(!bfs.empty()) {
            pii cur = bfs.top().second;
            int i = cur.first, j = cur.second;
            bfs.pop();
            if(vis[i][j]) continue;
            vis[i][j] = true;

            if(i != r-1) {
                int diff = grid[i][j] - grid[i+1][j];
                if(diff > 0) {
                    count += diff - 1;
                    grid[i + 1][j] += diff - 1;
                    bfs.push(mp(grid[i+1][j], mp(i+1, j)));
                }
            }
            if(i != 0) {
                int diff = grid[i][j] - grid[i-1][j];
                if(diff > 0) {
                    count += diff - 1;
                    grid[i - 1][j] += diff - 1;
                    bfs.push(mp(grid[i-1][j], mp(i-1, j)));
                }
            }
            if(j != c-1) {
                int diff = grid[i][j] - grid[i][j+1];
                if(diff > 0) {
                    count += diff - 1;
                    grid[i][j+1] += diff - 1;
                    bfs.push(mp(grid[i][j+1], mp(i, j+1)));
                }
            }
            if(j != 0) {
                int diff = grid[i][j] - grid[i][j-1];
                if(diff > 0) {
                    count += diff - 1;
                    grid[i][j-1] += diff - 1;
                    bfs.push(mp(grid[i][j-1], mp(i, j-1)));
                }
            }
            
        }

        cout << "Case #" << ti << ": " << count << "\n"; 
    }

    return 0;
}
