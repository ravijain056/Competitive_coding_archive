// Implementation using deque.

#include<bits/stdc++.h>
#include <sys/resource.h>

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

int n, m, a, b;
vl C;
vvi adj;
vb vis;
vi par;
deque<pll> F;

void dfs(int i) {
    vis[i] = true;
    for(int e : adj[i]) {
        if(vis[e]) continue;
        par[e] = i;
        dfs(e);
    }
}

void dfs2(int cur, int prev, int i, int depth) {
    pll back_pop = mp(-1, -1), front_pop = mp(-1, -1);

    if(F.front().second < i + depth - m) {
        front_pop = F.front();
        F.pop_front();
    }
    
    if(F.empty()) {
        F.push_front(front_pop);
        return;
    }
    
    if (F.back().second == i - depth) {
        back_pop = F.back();
        F.pop_back();
    }

    if(F.empty()) {
        if(front_pop.first != -1) F.push_front(front_pop);
        if(back_pop.first != -1) F.push_back(back_pop);
        return;
    }

    if(C[cur]!= 0) {
        ll curF = F.front().first + C[cur];
        if(back_pop.first > curF || back_pop.first == -1) {
            while(!F.empty() && F.back().first >= curF) {
                F.pop_back();
            }
            back_pop.first = curF;
            back_pop.second = i - depth;
        }
    }

    for(int e : adj[cur]) {
        if(e == prev) continue;
        dfs2(e, cur, i, depth+1);
    }

    if(back_pop.first != -1) {
        while(!F.empty() && F.back().first >= back_pop.first) {
            F.pop_back();
        }
        F.push_back(back_pop);
    }

    if(front_pop.first == -1) return;
    if(F.empty() || F.front().first > front_pop.first) {
        F.push_front(front_pop);
    }
    
}

int main() {
    const rlim_t kStackSize = 128 * 1024 * 1024;   // min stack size = 129 MB
    struct rlimit rl;
    int result;

    result = getrlimit(RLIMIT_STACK, &rl);
    if (result == 0)
    {
        if (rl.rlim_cur < kStackSize)
        {
            rl.rlim_cur = kStackSize;
            result = setrlimit(RLIMIT_STACK, &rl);
            if (result != 0)
            {
                fprintf(stderr, "setrlimit returned result = %d\n", result);
            }
        }
    }

    freopen("running_on_fumes_chapter_2_input.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);

    int t;
    cin >> t;

    for(int ti = 1; ti <= t; ti++) {
        cin >> n >> m >> a >> b;
        C.resize(n+1);
        adj.clear();
        adj.resize(n+1);
        vis.assign(n+1, false);
        par.resize(n+1);
        
        for(int i = 1; i <= n; i++) {
            int p;
            cin >> p >> C[i];
            if(p == 0) continue;
            adj[i].push_back(p);
            adj[p].push_back(i);
        }

        par[b] = 0;
        dfs(b);
        F.clear();
        F.push_back(mp(0, 0));
        int cur = a, prev = -1;
        int i = 0;

        while(true) {
            prev = cur;
            cur = par[cur];
            i++;
            if(F.front().second < i - m) F.pop_front();
            if(F.empty()) break;
            if(cur == b) break;
            for(int e : adj[cur]) {
                if(e == prev || e == par[cur]) continue;
                dfs2(e, cur, i, 1);
            }
            if(C[cur] != 0) {
                ll curF = C[cur] + F.front().first;
                while(!F.empty() && F.back().first >= curF) {
                    F.pop_back();
                }
                F.push_back(mp(curF, i));
            }
        }
        ll ans;
        if(F.empty()) ans = -1;
        else ans = F.front().first;
        cout << "Case #" << ti << ": " << ans << "\n"; 
    }

    return 0;
}