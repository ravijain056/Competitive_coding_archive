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
        int n, k, y;
        cin >> n >> k;
        vi x(n);
        for(int i = 0; i < n; i++) cin >> x[i];
        for(int i = 0; i < n; i++) cin >> y;

        sort(x.begin(), x.end());

        vi dp(n), maxr(n+1);
        maxr[n] = 0;
        int ans = 0;
        for(int i = n-1; i >= 0; i--) {
            dp[i] = upper_bound(x.begin(), x.end(), x[i]+k) - x.begin() - i;
            maxr[i] = max(dp[i], maxr[i+1]);
            ans = max(ans, dp[i] + maxr[i+dp[i]]);
        }
        cout << ans << "\n";
    }

    return 0;
}