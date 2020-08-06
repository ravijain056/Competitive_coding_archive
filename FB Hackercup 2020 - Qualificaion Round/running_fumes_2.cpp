//Implementation using heap(priority_queue)

#include<bits/stdc++.h>
#include <sys/resource.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<long, int> pli;

#define mp make_pair


int n, m, a, b;
vector<vi> adj;
vector<ll> minC;
vi C;
vi path;
int pi;
priority_queue<pli, vector<pli>, greater<pli> > heap;

void dfs(int i, int prev=-1) {
    path[pi++] = i;
    if(path[pi-1] == b) return;
    for(int j = 0; j < adj[i].size(); j++) {
        int c = adj[i][j];
        if(prev == c) continue;
        dfs(c, i);
        if(path[pi-1] == b) return;
    }
    pi--;
}

void explore(int cur, int prev, int depth, int depth_lim, int heap_lim) {
    if(depth < depth_lim) return;
    vector<pli> explore_bin;

    pli heap_cur;
    bool pos = true;
    while(true) {
        if(heap.empty()) {
            pos = false;
            break;
        }
        heap_cur = heap.top();
        if(heap_cur.second <= heap_lim) {
            explore_bin.push_back(heap_cur);
            heap.pop();
        }
        else break;
    }
    
    if(pos) {
        minC[cur] = heap_cur.first;
        if(C[cur] != 0) heap.push(mp(minC[cur] + C[cur], depth));

        for(int c : adj[cur]) {
            if(c == prev) continue;
            explore(c, cur, depth-1, depth_lim, heap_lim+1);
        }
    }

    for(pli p: explore_bin)
        heap.push(p);
    explore_bin.clear();
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
    freopen("output_1.txt", "w", stdout);

    int T;
    cin >> T;

    for(int ti = 1; ti <= T; ti++) {
        cin >> n >> m >> a >> b;
        a--; b--;

        C.resize(n);
        adj.clear();
        adj.resize(n);
        minC.assign(n, -1);
        path.assign(n, -1);
        heap = priority_queue<pli, vector<pli>, greater<pli> >();
        
        for(int i = 0; i < n; i++) {
            int p;
            cin >> p >> C[i];
            if(p==0) continue;
            adj[i].push_back(p-1);
            adj[p-1].push_back(i);
        }

        pi = 0;
        dfs(a);

        if(pi <= m) {
            cout << "Case #" << ti << ": " << 0 << "\n"; 
            continue;
        }

        heap.push(mp(0, 0));

        for(int i = 1; i < m; i++) {
            int prev = path[i-1], cur = path[i], next = path[i+1];

            minC[cur] = 0;
            if(C[cur] != 0) heap.push(mp(C[cur], i));
            
            for(int c : adj[cur]) {
                if(c == prev || c == next) continue;
                explore(c, cur, i-1, 0, i-m);
            }
        }

        bool pos = true;


        for(int i = m; i < path.size(); i++) {
            int prev = path[i-1], cur = path[i], next = -1;
            if(cur != b) next = path[i+1];

            pli heap_cur;
            while(true) {
                if(heap.empty()) {
                    pos = false;
                    break;
                }
                heap_cur = heap.top();
                if(heap_cur.second < i-m) heap.pop();
                else break;
            }
            
            if(!pos) break;
            minC[cur] = heap_cur.first;
            if(cur == b) break;

            if(C[cur] != 0) heap.push(mp(minC[cur] + C[cur], i));

            for(int c : adj[cur]) {
                if(c == prev || c == next) continue;
                explore(c, cur, i-1, i-m, i-m);
            }
        }

        ll ans = -1;
        if(pos) ans = minC[b];
        cout << "Case #" << ti << ": " << ans << "\n"; 
    }

    return 0;
}