#include<bits/stdc++.h>
#include <sys/resource.h>

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

int N, M, K;
vl P, L, H, X, Y;

vvi child;
vvl C;
ll ans;
vector<set<pll> > ghull;

inline double get_intersection_x(pll l1, pll l2) {
    double num = (l2.second - l1.second);
    double den = (l1.first - l2.first);
    return (num / den);
}

bool check(pll l1, pll l2, pll l3) {
    if(l2.first == l1.first && l2.second >= l1.second) return false;
    if(l2.first == l3.first && l2.second >= l3.second) return false;

    double pAx = get_intersection_x(l1, l2);
    double pBx = get_intersection_x(l2, l3);

    return pBx < pAx;
}

void add(int i, ll m, ll c) {
    auto ret = ghull[i].insert(mp(m, c));
    if(ret.second == false) return;

    auto it = ret.first;
    if(it != ghull[i].begin() && next(it) != ghull[i].end()) {
        if(!check(*prev(it), *it, *next(it))) {
            ghull[i].erase(it);
            return;
        }
    }

    if(it != ghull[i].begin()) {
        auto it2 = prev(it);
        while(it2 != ghull[i].begin()) {
            auto it3 = prev(it2);
            if(!check(*it3, *it2, *it)) {
                ghull[i].erase(it2);
                it2 = it3;
            } else break;
        }
    }

    auto it2 = next(it);
    if(it2 != ghull[i].end()) {
        while(true) {
            auto it3 = next(it2);
            if(it3 == ghull[i].end()) break;
            if(!check(*it, *it2, *it3)) {
                ghull[i].erase(it2);
                it2 = it3;
            } else break;
        }
    }
}

ll solve(int i, ll D){
    auto it = ghull[i].begin();
    double lim;
    auto it2 = next(it);
    if(it2 == ghull[i].end()) lim = -1;
    else lim = get_intersection_x(*it, *it2);
    while(H[i] < lim) {
        it = it2;
        it2 = next(it);
        if(it2 == ghull[i].end()) lim = -1;
        else lim = get_intersection_x(*it, *it2);
    }

    ll intercept = (H[i] * it->first + it->second) - (H[i] * D);
    
    for(int c : C[i]) {
        ll v;

        if(c >= H[i]) v = intercept;
        else {
            while(c < lim) {
                it = it2;
                it2 = next(it);
                if(it2 == ghull[i].end()) lim = -1;
                else lim = get_intersection_x(*it, *it2);
            }

            v = (c * it->first + it->second) - (c * D);
        }
        ans = (ans * ((v+1)%mod)) % mod;
    }
    return intercept;
}

void merge(int i, int e) {
    if(ghull[e].size() > ghull[i].size()) swap(ghull[i], ghull[e]);
    for(pll he : ghull[e]) add(i, he.first, he.second);
    ghull[e].clear();
}

void dfs(int i, ll D) {
    
    if(child[i].empty()) {
        add(i, D, 0);
        return;
    }

    for(int e : child[i]) {
        dfs(e, D + L[e]);
        merge(i, e);
    }

    ll k = solve(i, D);
    add(i, D, k);
}

int main() {

    struct rlimit rl = {RLIM_INFINITY, RLIM_INFINITY};
    if(setrlimit(RLIMIT_STACK, &rl) == -1)
        perror("setrlimit error \n");
    
    #ifdef LOCAL_DEV
        freopen("log_drivin_hirin_input.txt", "r", stdin);
        //freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    ll a, b, c, d;

    for(int ti = 1; ti <= t; ti++) {
        
        cin >> N >> M >> K;
        
        P.resize(N+1);
        L.resize(N+1);
        H.resize(N+1);
        X.resize(M);
        Y.resize(M);

        for(int i = 1; i <= K; i++) cin >> P[i];
        cin >> a >> b >> c;
        for(int i = K+1; i <= N; i++) 
            P[i] = ((a * P[i-2] + b * P[i-1] + c) % (i-1)) + 1;
        
        for(int i = 1; i <= K; i++) cin >> L[i];
        cin >> a >> b >> c >> d;
        for(int i = K+1; i <= N; i++) 
            L[i] = ((a * L[i-2] + b * L[i-1] + c) % d) + 1;
        
        for(int i = 1; i <= K; i++) cin >> H[i];
        cin >> a >> b >> c >> d;
        for(int i = K+1; i <= N; i++) 
            H[i] = ((a * H[i-2] + b * H[i-1] + c) % d) + 1;
        
        for(int i = 0; i < K; i++) cin >> X[i];
        cin >> a >> b >> c;
        for(int i = K; i < M; i++) 
            X[i] = ((a * X[i-2] + b * X[i-1] + c) % N) + 1;

        for(int i = 0; i < K; i++) cin >> Y[i];
        cin >> a >> b >> c >> d;
        for(int i = K; i < M; i++) 
            Y[i] = ((a * Y[i-2] + b * Y[i-1] + c) % d) + 1;

        child.clear();
        child.resize(N+1);
        C.clear();
        C.resize(N+1);
        ghull.clear();
        ghull.resize(N+1);
        
        for(int i = 0; i < M; i++) C[X[i]].pb(Y[i]);
        for(int i = 1; i <= N; i++) {
            child[P[i]].pb(i);
            sort(C[i].rbegin(), C[i].rend());
        }
        

        ans = 1;

        dfs(1, 0);

        cout << "Case #" << ti << ": " << ans << "\n"; 
    }

    return 0;
}
