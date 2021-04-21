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

int s, ra, pa, rb, pb, c;
vvi adj;
vb vis;

int getid(int r, int p) {
    return s * 2 * (r-1) + (p-1);
}

int dfs(int i, int j, bool turn, bool must) {
    if(!turn) {
        int score = INT_MIN;
        for(int e : adj[i]) {
            if(vis[e]) continue;
            vis[e] = true;
            score = max(dfs(e, j, turn^1^must, must), score);
            vis[e] = false;
        }
        if(score == INT_MIN) {
            if(must) return 0;
            return dfs(i, j, turn^1, true);
        }
        return score + 1;
    } else {
        int score = INT_MAX;
        for(int e : adj[j]) {
            if(vis[e]) continue;
            vis[e] = true;
            score = min(dfs(i, e, turn^1^must, must), score);
            vis[e] = false;
        }
        if(score == INT_MAX) {
            if(must) return 0;
            return dfs(i, j, turn^1, true);
        }
        return score - 1;
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
        cin >> s >> ra >> pa >> rb >> pb >> c;
        adj.clear();
        adj.resize(2 * s * s);
        vb C(2*s*s, true);
        for(int i = 0; i < c; i++) {
            int r, p;
            cin >> r >> p;
            C[getid(r, p)] = false;
        }
        int ci = 0;
        for(int r = 1; r <= s; r++) {
            for(int p = 1; p <= 2*r - 1; p++) {
                if(p != 1 && C[getid(r, p)] && C[getid(r, p-1)]) {
                    adj[getid(r, p)].pb(getid(r, p-1));
                    adj[getid(r, p-1)].pb(getid(r, p));
                }
                if(r != 1 && (p%2 == 0) && C[getid(r, p)] && C[getid(r-1, p-1)]) {
                    adj[getid(r, p)].pb(getid(r-1, p-1));
                    adj[getid(r-1, p-1)].pb(getid(r, p));
                }
            }
        }
        
        vis.assign(2*s*s, false);
        vis[getid(ra, pa)] = true;
        vis[getid(rb, pb)] = true;

        cout << "Case #" << ti << ": " ; 
        cout << dfs(getid(ra, pa), getid(rb, pb), false, false) << "\n";
    }

    return 0;
}