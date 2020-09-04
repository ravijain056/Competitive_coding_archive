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

    int n, k;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;

    vector<vvi> dp(n+1, vvi(k+1, vi(n+1, INT_MIN)));

    dp[0][0][0] = 0;

    for(int i = 0; i < n; i++) {
        bool e0 = s[i] == t[0], e1 = s[i] == t[1], e01 = t[0] == t[1];
        for(int cnt0 = 0; cnt0 <= i; cnt0++) {
            for(int ck = 0; ck < min(k, i+1); ck++) {
                dp[i+1][ck][cnt0+e0] = max(dp[i+1][ck][cnt0+e0], 
                                            dp[i][ck][cnt0] + (e1 ? cnt0 : 0));
                
                dp[i+1][ck+1][cnt0+1] = max(dp[i+1][ck+1][cnt0+1],
                                            dp[i][ck][cnt0] + (e01 ? cnt0 : 0));
                
                dp[i+1][ck+1][cnt0+e01] = max(dp[i+1][ck+1][cnt0+e01],
                                                dp[i][ck][cnt0] + cnt0);
            }
            if(i + 1 >= k)
                dp[i+1][k][cnt0+e0] = max(dp[i+1][k][cnt0+e0], 
                                            dp[i][k][cnt0] + (e1 ? cnt0 : 0));
        }
    }

    int ans = INT_MIN;

    for(int ck = 0; ck <= k; ck++) {
        for(int cnt0 = 0; cnt0 <= n; cnt0++) {
            ans = max(ans, dp[n][ck][cnt0]);
        }
    }

    cout << ans << "\n";
    return 0;
}