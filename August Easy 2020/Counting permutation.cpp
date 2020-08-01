#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9+7;

int main() {
   
    int n, m;
    cin >> n >> m;

    vector<pair<int, int> > dp(n+1, make_pair(0, 0));
    dp[0] = make_pair(1, 0);

    for(int i = 1; i <= m; i++) {
        for(int j = 0; j < 2; j++) {
            int t = (n-i) / m;
            while(t--) {
                for(int k = n; k>= 0; k--) {
                    dp[k].first += dp[k].second;
                    dp[k].first %= mod;
                    if(k != 0) dp[k].second = dp[k-1].first;
                }
            }

            for(int k = 0; k <= n; k++) {
                dp[k] = make_pair(dp[k].first + dp[k].second, 0);
                dp[k].first %= mod;
            }
        }
    }

    int tot = 0;
    ll fac = 1;
    for(int k = n; k >= 0; k--) {
        if(k % 2 == 0) tot = (tot + dp[k].first * fac) % mod;
        else tot = (tot + mod - ((dp[k].first * fac)%mod)) % mod;
        fac = (fac * (n-k + 1)) % mod;
    }

    cout << tot << "\n";
    return 0;
}