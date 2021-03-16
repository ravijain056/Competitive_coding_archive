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

    int n, m;
    cin >> n >> m;
    vvi A(n, vi(m));
    vi maxR(n), maxC(m);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            cin >> A[i][j];
            maxR[i] = max(maxR[i], A[i][j]);
            maxC[j] = max(maxC[j], A[i][j]);
        }

    unordered_set<int> specX(maxR.begin(), maxR.end()), specY(maxC.begin(), maxC.end());

    vvi out(n, vi(m));
    queue<pii> pos;
    int x = -1, y = -1; 

    for(int t=n*m; t > 0;t--) {
        bool sx = specX.find(t) != specX.end();
        bool sy = specY.find(t) != specY.end();
        
        if(sx) x++;
        if(sy) y++;
        if(sx || sy) out[x][y] = t;
        else {
            out[pos.front().first][pos.front().second] = t;
            pos.pop();
        }
        
        if(sx) 
            for(int ny = y-1; ny >= 0; ny--) 
                pos.push(mp(x, ny));
            
        if(sy)
            for(int nx = x-1; nx >= 0; nx--) 
                pos.push(mp(nx, y));
    }


    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) cout << out[i][j] << " ";
        cout << "\n";
    }
    

    return 0;
}
