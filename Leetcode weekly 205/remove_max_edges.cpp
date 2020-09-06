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

vector<vpii> adjA, adjB, adjC;
vb vis, vise;
queue<pii> bfs;

void dfs(int i, int type) {
    vis[i] = true;
    for(pii ei : adjC[i]) {
        if(!vis[ei.first]) {
            vise[ei.second] = true;
            dfs(ei.first, type);
        }
    }
    if(type == 0) {
        for(pii ei : adjA[i]) bfs.push(ei);
    } else {
        for(pii ei : adjB[i]) bfs.push(ei);
    }
}
 
int solve(int n, vvi edges) {
    adjA.clear();
    adjB.clear();
    adjC.clear();
    adjA.resize(n+1);
    adjB.resize(n+1);
    adjC.resize(n+1);
    vise.assign(edges.size(), false);
    
    for(int i = 0; i < edges.size(); i++) {
        int t = edges[i][0], u = edges[i][1], v = edges[i][2];
        if(t == 1) {
            adjA[u].pb(mp(v, i));
            adjA[v].pb(mp(u, i));
        } else if(t == 2) {
            adjB[u].pb(mp(v, i));
            adjB[v].pb(mp(u, i));
        } else {
            adjC[u].pb(mp(v, i));
            adjC[v].pb(mp(u, i));
        }
    }

    vis.assign(n+1, false);
    vis[0] = true;
    dfs(1, 0);
    while(!bfs.empty()) {
        pii ei = bfs.front();
        bfs.pop();
        if(!vis[ei.first]) {
            vise[ei.second] = true;
            dfs(ei.first, 0);
        }
    }
    for(bool v : vis) if(!v) return -1;
    vis.assign(n+1, false);
    vis[0] = true;
    dfs(1, 1);
    while(!bfs.empty()) {
        pii ei = bfs.front();
        bfs.pop();
        if(!vis[ei.first]) {
            vise[ei.second] = true;
            dfs(ei.first, 1);
        }
    }
    for(bool v : vis) if(!v) return -1;
    int cnt = 0;
    for(bool v : vise) if(!v) cnt++;
    return cnt;
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

    for(int ti = 1; ti <= t; ti++) {
        int n, m;
        cin >> n >> m;
        vvi edges(m, vi(3));
        for(int i = 0; i < m; i++) {
            cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
        }
        cout << solve(n, edges) << "\n";
    }

    return 0;
}