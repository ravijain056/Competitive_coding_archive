// TLE.

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

vi xrefs, yrefs;
vector<ll> x, y, p;
int n;
ll ans;

ll calc_distance() {
    ll res = 0;
    for(int i = 0; i < n; i++) {
        ll d = INT_MAX;
        for(int x_ref: xrefs) {
            d = min(d, abs(x[i] - x_ref));
        }
        for(int y_ref : yrefs) {
            d = min(d, abs(y[i] - y_ref));
        }
        res += d * p[i];
    }
    return res;
}

void dfs(int i, int k) {
    if(k == 0) {
        ans = min(ans, calc_distance());
        return;
    }
    if(i == n) return;

    xrefs.push_back(x[i]);
    dfs(i, k-1);
    xrefs.pop_back();
    
    yrefs.push_back(y[i]);
    dfs(i+1, k-1);
    yrefs.pop_back();

    dfs(i+1, k);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    xrefs.push_back(0);
    yrefs.push_back(0);

    cin >> n;

    x.resize(n);
    y.resize(n);
    p.resize(n);

    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> p[i];
    }

    bool zero_ans = false;

    for(int k = 0; k <= n; k++) {
        ans = LONG_LONG_MAX;
        if(!zero_ans) dfs(0, k);
        else ans = 0;
        if(ans == 0) zero_ans = true;
        cout << ans << "\n";
    }

    return 0;
}