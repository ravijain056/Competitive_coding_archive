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

int solve(string s, vi& cost) {
    int ans = 0;
    int n = s.length();
    priority_queue<int> del_cost;
    del_cost.push(cost[0]);
    for(int i = 1; i < n; i++) {
        if(s[i] != s[i-1]) {
            del_cost.pop();
            while(!del_cost.empty()) {
                ans += del_cost.top();
                del_cost.pop();
            }
        }
        del_cost.push(cost[i]);
    }
    del_cost.pop();
    while(!del_cost.empty()) {
        ans += del_cost.top();
        del_cost.pop();
    }
    return ans;
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
        string s;
        cin >> s;
        int n;
        cin >> n;
        vi cost(n);
        for(int i = 0; i < n; i++) cin >> cost[i];
        
        cout << solve(s, cost) << "\n";
    }

    return 0;
}