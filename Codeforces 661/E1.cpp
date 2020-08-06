#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define mp make_pair

int n;
ll S;

vector<vector<pair<int, int> > > adj;
vector<bool> vis;
vector<ll> W;
vector<int> cnt;

int dfs(int i) {
    vis[i] =  true;
    if(adj[i].size() == 1 && i != 0) return 1;
    int leafcount = 0;
    for(auto ei : adj[i]) {
        int e = ei.first, id = ei.second;
        if(vis[e]) continue;
        cnt[id] = dfs(e);
        leafcount += cnt[id];
    }
    return leafcount;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while(t--) {
        cin >> n >> S;
        
        adj.clear();
        adj.resize(n);
        vis.assign(n, false);
        W.resize(n-1);
        cnt.resize(n-1);

        for(int i = 0; i < n-1; i++) {
            int u, v;
            cin >> u >> v >> W[i];
            adj[u-1].push_back(make_pair(v-1, i));
            adj[v-1].push_back(make_pair(u-1, i));
        }

        dfs(0);

        ll curs = 0;
        priority_queue<pll> moves;
        for(int i = 0; i < n-1; i++) {
            curs += W[i] * cnt[i];
            moves.push(mp(cnt[i] * (W[i] - W[i]/2), i));
        }
        curs -= S;
        ll cnt1 = 0;
        while(curs > 0) {
            cnt1++;
            pll cur = moves.top();
            if(cur.first == 0) break;
            curs -= cur.first;
            W[cur.second] /= 2;
            moves.push(mp(cnt[cur.second] * (W[cur.second] - W[cur.second] / 2), cur.second));
            moves.pop();
        }
        cout << cnt1 << "\n";
    }

    return 0;
}