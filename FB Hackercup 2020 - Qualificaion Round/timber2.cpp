#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define vt vector
#define mp make_pair

int main() {
    freopen("timber_input.txt", "r", stdin);
    freopen("output_1.txt", "w", stdout);

    int T;
    cin >> T;

    for(int ti = 1; ti <= T; ti++) {
        int n;
        cin >> n;

        vt<pii> trees(n);

        for(int i = 0; i < n; i++) {
            int p, h;
            cin >> p >> h;
            trees[i] = mp(p, h);
        }

        sort(trees.begin(), trees.end());

        unordered_map<int, int> dp;
        int ans = 0;

        for(int i = 0; i < n; i++) {
            int pi = trees[i].first, hi = trees[i].second;

            //falls right
            int key = pi+hi;
            int val = hi;
            if(dp.find(pi) != dp.end()) val += dp[pi];
            ans = max(val, ans);

            if(dp.find(key) != dp.end()) dp[key] = max(dp[key], val);
            else dp.insert(mp(key, val));

            //falls left
            key = pi;
            val = hi;
            if(dp.find(pi-hi) != dp.end()) val += dp[pi-hi];

            if(dp.find(key) != dp.end()) dp[key] = max(dp[key], val);
            else dp.insert(mp(key, val));
            ans = max(val, ans);
        }

        cout << "Case #" << ti << ": " << ans << "\n"; 
    }

    return 0;
}