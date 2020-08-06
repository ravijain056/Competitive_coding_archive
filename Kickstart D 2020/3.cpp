#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair

ll n, a, b;
vector<int> parent;
vector<vector<int> > children;
vector<ll> childCountA, childCountB, path;

void dfs(int i) {
    path.push_back(i);
    for(int c : children[i]) {
        dfs(c);
    }
    path.pop_back();
    
    int sz = path.size();
    if(sz >= a) childCountA[path[sz-a]] += childCountA[i];
    if(sz >= b) childCountB[path[sz-b]] += childCountB[i];
}

void calcChildCounts() {
    childCountA.assign(n, 1);
    childCountB.assign(n, 1);
    dfs(0);
    return;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for(int ti=1; ti <= T; ti++) {
        cin >> n >> a >> b;

        parent.clear();
        parent.resize(n);
        children.clear();
        children.assign(n, vector<int>());
        
        for(int i = 1; i < n; i++) {
            int par;
            cin >> par;
            children[--par].push_back(i);
        }

        calcChildCounts();

        double ans = 0;
        double addcount = 0, subcount = 0;

        for(int i = 0; i < n; i++) {
            addcount += childCountB[i] + childCountA[i];
            subcount += (childCountB[i] * childCountA[i]);
        }
        ans = (addcount / n) - (subcount/(n*n));
        cout << fixed << setprecision(6) << "Case #" << ti << ": " << ans << "\n";   
    }

    return 0;
}