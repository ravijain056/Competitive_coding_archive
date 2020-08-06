//Slightly different problem statement. Solution for maximum total of non-intersecting intervals.

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define vt vector
#define mp make_pair

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

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

        map<int, int, greater<int> > dp;
        
        int ans = trees[0].second;
        dp.insert(mp(trees[0].first, trees[0].second)); 
        
        for(int i = 1; i < n; i++) {
            int pi = trees[i].first, hi = trees[i].second;
            
            auto it_right = dp.lower_bound(pi);
            int key_right = pi+hi;
            int val_right = (*it_right).second + hi;

            auto it_left = dp.lower_bound(pi - hi);
            int key_left = pi;
            int val_left = (*it_left).second + hi;
            
            auto it2_right = dp.insert(mp(key_right, val_right));
            
            if(!it2_right.second) {
                val_right = max(dp[pi], val_right);
                dp[pi] = val_right;
            }
            
            it_right = dp.lower_bound(key_right);
            bool begin = it_right == dp.begin();
            it_right--;
            while(!begin && (*it_right).second <= val_right) {
                dp.erase(it_right);
                it_right = dp.lower_bound(key_right);
                begin = it_right == dp.begin();
                it_right--;
            }
            
            auto it2_left = dp.insert(mp(key_left, val_left));
            
            if(!it2_left.second) {
                val_left = max(dp[pi], val_left);
                dp[pi] = val_left;
            }

            it_left = dp.lower_bound(key_left);
            begin = it_left == dp.begin();
            it_left--;
            while(!begin && (*it_left).second <= val_left) {
                dp.erase(it_left);
                it_left = dp.lower_bound(key_left);
                begin = it_left == dp.begin();
                it_left--;
            }

            ans = max(ans, val_right);
            ans = max(ans, val_left);
        }

        cout << "Case #" << ti << ": " << ans << "\n"; 
    }

    return 0;
}