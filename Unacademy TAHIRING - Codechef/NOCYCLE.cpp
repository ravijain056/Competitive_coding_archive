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

int n, m;
vvi adj;
vb vis;

int dfs(int i) {
    vis[i] = true;
    int ret = 1;
    for(int e : adj[i]) {
        if(vis[e]) continue;
        ret += dfs(e);
    }
    return ret;
}

int main() {

    #ifdef LOCAL_DEV
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    vis.assign(n, false);
    adj.assign(n, vi());

    for(int i =0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    int req = 0;

    for(int i = 0; i < n; i++) {
        if(!vis[i]){
            req += dfs(i) - 1;
        }
    }

    cout << m - req << "\n";

    return 0;
}