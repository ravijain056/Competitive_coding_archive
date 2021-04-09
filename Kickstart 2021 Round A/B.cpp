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

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                cin >> grid[i][j];
            }
        }

        vvi up(grid);
        vvi down(grid);
        vvi left(grid);
        vvi right(grid);

        for(int i = 0; i < r; i++) {
            for(int j = 1; j < c; j++) {
                if(grid[i][j]!= 0) left[i][j] += left[i][j-1];
            }
            for(int j = c-2; j >= 0; j--) {
                if(grid[i][j]!= 0) right[i][j] += right[i][j+1];
            }
        }

        for(int j = 0; j < c; j++) {
            for(int i = 1; i < r; i++) {
                if(grid[i][j]!= 0) up[i][j] += up[i-1][j];
            }
            for(int i = r-2; i >= 0; i--) {
                if(grid[i][j]!= 0) down[i][j] += down[i+1][j];
            }
        }

        ll count = 0;

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                //left 
                if(left[i][j] >= 4) {
                    if(up[i][j] >= 2) {
                        count += min(up[i][j], left[i][j]/2) - 1;
                    }
                    if(down[i][j] >= 2) {
                        count += min(down[i][j], left[i][j]/2) - 1;
                    }
                }
                //right
                if(right[i][j] >= 4) {
                    if(up[i][j] >= 2) {
                        count += min(up[i][j], right[i][j]/2) - 1;
                    }
                    if(down[i][j] >= 2) {
                        count += min(down[i][j], right[i][j]/2) - 1;
                    }
                }
                //up
                if(up[i][j] >= 4) {
                    if(left[i][j] >= 2) {
                        count += min(left[i][j], up[i][j]/2) - 1;
                    }
                    if(right[i][j] >= 2) {
                        count += min(right[i][j], up[i][j]/2) - 1;
                    }
                }
                //down
                if(down[i][j] >= 4) {
                    if(left[i][j] >= 2) {
                        count += min(left[i][j], down[i][j]/2) - 1;
                    }
                    if(right[i][j] >= 2) {
                        count += min(right[i][j], down[i][j]/2) - 1;
                    }
                }
                
            }
        }

        /*for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++)  cout << up[i][j] << " ";
            cout << "\n";
        }
        cout << "\n";
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++)  cout << down[i][j] << " ";
            cout << "\n";
        }
        cout << "\n";
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++)  cout << right[i][j] << " ";
            cout << "\n";
        }
        cout << "\n";
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++)  cout << left[i][j] << " ";
            cout << "\n";
        }
        cout << "\n";
        */
        cout << "Case #" << ti << ": " << count << "\n"; 
        /*cout << "\n";
        cout << "\n";*/
    }

    return 0;
}
