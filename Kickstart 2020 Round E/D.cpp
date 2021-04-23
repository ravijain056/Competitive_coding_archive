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
typedef pair<ll, pair<int, int> > plp;

#define mp make_pair
#define pb push_back

int n, m, s, r;
vvi adj;
vvl cost;
vvi recs;
vvi irec;
vi orec;
vector<vb> vis;

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
        cin >> n >> m >> s >> r;
        
        adj.clear();
        adj.resize(n+1);
        for(int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        priority_queue<plp, vector<plp>, greater<plp> > que;
        cost.assign(n+1, vl(s+1, LONG_LONG_MAX));
        for(int i = 1; i <= n; i++) {
            int c;
            cin >> c;
            while(c--) {
                int st;
                cin >> st;
                que.push(mp(0, mp(i, st)));
            }
        }

        irec.clear();
        irec.resize(r);
        recs.clear();
        recs.resize(s+1);
        orec.resize(r);
        for(int i = 0; i < r; i++) {
            int k;
            cin >> k;
            while(k--){
                int ing;
                cin >> ing;
                irec[i].pb(ing);
                recs[ing].pb(i);
            }
            cin >> orec[i];
        }

        vis.assign(n+1, vb(s+1, false));
        ll ans = -1;
        while(!que.empty()) {
            auto cur = que.top();
            ll c = cur.first;
            int u = cur.second.first, st = cur.second.second;
            que.pop();
            if(c >= 1e12) break;
            if(st == 1) {
                ans = c;
                break;
            }
            if(c >= cost[u][st]) continue;
            cost[u][st] = c;

            for(int v : adj[u]) que.push(mp(c+1, mp(v, st)));

            for(int ri : recs[st]) {
                ll tot = 0;
                bool pos = true;
                for(int ing : irec[ri]) {
                    if(cost[u][ing] == LONG_LONG_MAX) {
                        pos = false;
                        break;
                    }
                    tot += cost[u][ing];
                }
                if(pos) que.push(mp(tot, mp(u, orec[ri])));
            }

        }

        cout << "Case #" << ti << ": " << ans << "\n"; 
    }

    return 0;
}