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
vector<int> cnt, C;

int dfs(int i) {
    vis[i] =  true;
    if(adj[i].size() == 1 && i!= 0) return 1;
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

    int t;
    cin >> t;

    while(t--) {
        cin >> n >> S;
        
        adj.clear();
        adj.resize(n);
        vis.assign(n, false);
        W.resize(n-1);
        C.resize(n-1);
        cnt.resize(n-1);

        for(int i = 0; i < n-1; i++) {
            int u, v;
            cin >> u >> v >> W[i] >> C[i];
            adj[u-1].push_back(make_pair(v-1, i));
            adj[v-1].push_back(make_pair(u-1, i));
        }

        dfs(0);

        ll initS = 0;
        priority_queue<pll> moves1, moves2;
        for(int i = 0; i < n-1; i++) {
            initS += W[i] * cnt[i];
            if(C[i] == 1) moves1.push(mp(cnt[i] * (W[i] - W[i]/2), i));
            else moves2.push(mp(cnt[i] * (W[i] - W[i]/2), i));
        }
        ll curs = initS - S;
        vl impact1, impact2;

        while(!moves1.empty() && curs > 0) {
            pll cur1 = moves1.top();
            if(cur1.first == 0) break;
            curs -= cur1.first;
            impact1.push_back(cur1.first);
            int i1 = cur1.second;
            W[i1] /= 2;
            moves1.push(mp(cnt[i1] * (W[i1] - W[i1]/2), i1));
            moves1.pop();
        }

        curs = initS - S;
        while(!moves2.empty() && curs > 0) {
            pll cur2 = moves2.top();
            if(cur2.first == 0) break;
            curs -= cur2.first;
            impact2.push_back(cur2.first);
            int i2 = cur2.second;
            W[i2] /= 2;
            moves2.push(mp(cnt[i2] * (W[i2] - W[i2]/2), i2));
            moves2.pop();
        }

        ll cnt1 = LONG_LONG_MAX;
        ll cur1 = 0;
        ll cur2 = 0;
        ll cur2i = 0;
        for(ll i : impact1) cur1 += i;

        if(initS - cur1 <= S) cnt1 = impact1.size();
        else {
            while(initS - cur1 - cur2 > S) {
                if(cur2i == impact2.size()) break;
                cur2 += impact2[cur2i++];
            }
            cnt1 = min(cnt1, (ll)impact1.size() + 2 * cur2i);
        }

        while(!impact1.empty()) {
            cur1 -= impact1.back();
            impact1.pop_back();

            while(initS - cur1 - cur2 > S) {
                if(cur2i == impact2.size()) break;
                cur2 += impact2[cur2i++];
            }

            if(initS - cur1 - cur2 > S) break;
            cnt1 = min(cnt1, (ll)impact1.size() + 2 * cur2i);
        }

        cout << cnt1 << "\n";
    }

    return 0;
}