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

int n, k;
vi par;
string s;
vvi childs;
vb infected;
vector<map<int, ll> > setcnt;
vi curset, globset;

void subcs(int i, int cs) {
    if(cs == 0) return;
    setcnt[i][cs]--;
    if(setcnt[i][cs] == 0)
        setcnt[i].erase(cs);
}

void addcs(int i, int cs) {
    if(setcnt[i].find(cs) != setcnt[i].end()) {
        setcnt[i][cs]++;
    } else {
        setcnt[i].insert(mp(cs, 1));
    }
}

void addset(int i, int j) {
    for(auto it : setcnt[j]) {
        if(setcnt[i].find(it.first) != setcnt[i].end()) {
            setcnt[i][it.first] += it.second;
        } else {
            setcnt[i].insert(mp(it.first, it.second));
        }
    }
}

void subset(int i, int j) {
    for(auto it : setcnt[j]) {
        setcnt[i][it.first] -= it.second;
        if(setcnt[i][it.first] == 0) setcnt[i].erase(it.first);
    }
}

void dfs(int i) {
    if(!infected[i]) curset[i] = 1;
    for(int c : childs[i]) {
        dfs(c);
        addset(i, c);
        if(!infected[i]) {
            curset[i] += curset[c];
            subcs(i, curset[c]);
        }
    } 
    if(!infected[i]) addcs(i, curset[i]);
    else addcs(i, 0);
}

void dfs2(int i, int cs) {
    if(!infected[i]) {
        if(cs != 0) globset[i] = cs;
        else globset[i] = curset[i];
    }
    for(int c : childs[i]) {
        dfs2(c, globset[i]);
    }
}

ll calc(ll b, ll c) {
    ll a = b+c;
    return (a * (a-1) - b * (b-1) - c * (c-1)) / 2;
}

int main() {

    #ifdef LOCAL_DEV
        freopen("quarantine_input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    const rlim_t kStackSize = 128 * 1024 * 1024;   // min stack size = 128 MB
    struct rlimit rl;
    int result;

    result = getrlimit(RLIMIT_STACK, &rl);
    if (result == 0 && rl.rlim_cur < kStackSize) {
            rl.rlim_cur = kStackSize;
            result = setrlimit(RLIMIT_STACK, &rl);
            if (result != 0) 
                fprintf(stderr, "setrlimit returned result = %d\n", result);
    }

    int t;
    cin >> t;

    for(int ti = 1; ti <= t; ti++) {
        cin >> n >> k;
        infected.assign(n+1, false);
        par.resize(n+1);
        childs.clear();
        childs.resize(n+1);
        setcnt.clear();
        setcnt.resize(n+1);
        curset.assign(n+1, 0);
        globset.assign(n+1, 0);

        cin >> s;
        for(int i = 0; i < s.length(); i++) 
            if(s[i] == '#') infected[i+1] = true;

        for(int i = 0; i < k; i++) {
            cin >> par[i + 2];
            childs[par[i+2]].push_back(i+2);
        }
        ll a, b, c;
        cin >> a >> b >> c;
        for(int i = k ; i < n-1; i++) {
            par[i+2] = ((a * par[i] + b * par[i+1] + c) % (i+1))+1;
            childs[par[i+2]].push_back(i+2);
        }
        
        dfs(1);
        dfs2(1, 0);

        ll tot = 0, numways = 0, maxdiff = 0;

        for(auto it : setcnt[1]) {
            if(it.first <= 1) continue;
            tot += it.first * (it.first - 1) * it.second / 2;
        }
        setcnt[0] = setcnt[1];
        for(int j = 2; j <= n; j++) {
            int i = par[j];
            setcnt[1] = setcnt[0];
            ll diff = 0;
            if(!infected[i] && !infected[j]) {
                addcs(1, curset[j]);
                addcs(1, globset[j] - curset[j]);
                subcs(1, globset[j]);
                diff -= calc(curset[j], globset[j] - curset[j]);
            }
            subset(1, j);
            ll x = setcnt[j].rbegin()->first;
            ll y = setcnt[1].rbegin()->first;
            ll d = setcnt[j].rbegin()->second;
            ll e = setcnt[1].rbegin()->second;
            diff += calc(x, y);

            if(diff > maxdiff) {
                maxdiff = diff;
                numways = x * y * d * e;
            } else if(diff == maxdiff) {
                if(x == 0 && y == 0) numways += d * e;
                else if(y == 0) numways += (n-e) * e;
                else if(x == 0) numways += d * (n-d);
                else numways += x * y * d * e;
            }
        }
        cout << "Case #" << ti << ": " << tot + maxdiff << " " << numways << "\n"; 
    }

    return 0;
}