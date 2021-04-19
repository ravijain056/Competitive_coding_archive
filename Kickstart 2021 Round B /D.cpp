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

const int sz = 2e5+1;
vector<vpii> adj;
vi pL;
vl pA;
vb vis;
vl segtree(sz*2, 0);
vector<vpii> queries;
vl ans;

ll getGCD(int l, int r) {
    ll res = 0;
    l += sz;
    r += sz;
    for(;l < r; l >>= 1, r >>= 1) {
        if(l&1) res = __gcd(res, segtree[l++]);
        if(r&1) res = __gcd(res, segtree[--r]);
    }
    return res;
}

void update(int key, ll value) {
    int k = key + sz;
    segtree[k] = value;
    for(; k > 1; k >>= 1)
        segtree[k >> 1] = __gcd(segtree[k], segtree[k^1]);

}

void dfs(int i) {
    if(vis[i]) return;
    vis[i] = true;

    for(pii wi : queries[i]) {
        int w = wi.first, qi = wi.second;
        ans[qi] = getGCD(0, w+1);
    }
    
    for(pii ej : adj[i]) {
        int e = ej.first;
        int j = ej.second;
        if(vis[e]) continue;
        update(pL[j], pA[j]);
        dfs(e);
        update(pL[j], 0);
    }
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
        int n, q;
        cin >> n >> q;

        adj.clear();
        adj.resize(n+1);
        pL.resize(n-1);
        pA.resize(n-1);

        queries.clear();
        queries.resize(n+1);
        vis.assign(n+1, false);
        ans.resize(q);

        for(int i = 0; i < n-1; i++) {
            int x, y;
            cin >> x >> y >> pL[i] >> pA[i];
            adj[x].pb(mp(y, i));
            adj[y].pb(mp(x, i));
        }

        cout << "Case #" << ti << ": " ; 

        for(int i = 0; i < q; i++) {
            int c, w;
            cin >> c >> w;
            queries[c].pb(mp(w, i));
        }

        dfs(1);
        for(ll a : ans) cout << a << " ";
        cout << "\n";
    }    
    return 0;
}

