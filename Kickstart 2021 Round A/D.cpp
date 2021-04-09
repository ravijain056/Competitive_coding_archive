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
        int n;
        cin >> n;

        vvi A(n, vi(n));
        vvi B(n, vi(n));
        vi R(n), C(n);
        int out = 0;
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) cin >> A[i][j];
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) {
                cin >> B[i][j];
                out += B[i][j];
            }

        for(int i = 0; i < n; i++) cin >> R[i];
        for(int i = 0; i < n; i++) cin >> C[i];
        

        vb vis(2*n, false);

        priority_queue<pii > heap;

        for(int i = 0; i < 2*n; i++) {
            if(vis[i]) continue;
            heap.push(mp(0, i));

            while(!heap.empty()) {
                int cur = heap.top().second;
                int w = heap.top().first;
                heap.pop();
                if(vis[cur]) continue;

                out -= w;
                vis[cur] = true;

                if(cur < n) { //row
                    int r = cur;
                    for(int c = 0; c < n; c++) {
                        if(vis[c+n]) continue;
                        if(B[r][c] != 0) heap.push(mp(B[r][c], c+n));
                    }
                } else { //col
                    int c = cur - n;
                    for(int r = 0; r < n; r++) {
                        if(vis[r]) continue;
                        if(B[r][c] != 0) heap.push(mp(B[r][c], r));
                    }
                }
            }
        }


        cout << "Case #" << ti << ": "  << out << "\n"; 
    }

    return 0;
}
