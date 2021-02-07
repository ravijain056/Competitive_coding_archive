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

int n, m;
int a, b;
vector<vector<pii> > adj;
vi vis, vise;
unordered_set<int> cycle;


int dfscycle(int i) {
    if(vis[i]) return i;
    vis[i] = 1;
    for(pii e : adj[i]) {
        if(!vise[e.second]) {
            vise[e.second] = 1;
            int ret = dfscycle(e.first);
            if(ret > 0) {
                cycle.insert(e.second);
                if(i == ret) return 0;
                else return ret;
            } else if(ret == 0) return 0;
        }
    }
    return -1;
}

int dfs(int i) {
    if (i == b) return 0;
    for(pii ei : adj[i]) {
        if(!vise[ei.second]) {
            vise[ei.second] = 1;
            int ret = dfs(ei.first);
            if(ret >= 0) {
                if(cycle.find(ei.second) == cycle.end()) return ret+1;
                return ret;
            }
        }
    }
    return -1;
}

int main() {

    #ifdef LOCAL_DEV
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    cin >> a >> b;

    adj.resize(n+1);

    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(mp(y, i));
        adj[y].push_back(mp(x, i));
    }
 
    vise.assign(m, 0);
    if(n == m) {
        vis.assign(n+1, 0);
        dfscycle(a);
        vise.assign(m, 0);
    }
    cout << dfs(a);

    return 0;
}