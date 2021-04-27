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

ll Q(ll x) {
    return x * (x-1) / 2;
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
        int n;
        double p;
        cin >> n >> p;

        vector<vector<double>> dp(n, vector<double>(n));
        
        dp[0][0] = 0;
        for(int i = 1; i < n; i++) {
            dp[i][0] = 1 + p * dp[i-1][0] * Q(i) / Q(i+1) 
                        + (1-p) * dp[i-1][0] * (Q(i) + i) / (Q(i+1)); 

            dp[0][i] = 1 + p * dp[0][i-1] * (Q(i) + i) / Q(i+1)
                        + (1-p) * dp[0][i-1] * Q(i) / Q(i+1);
            
            for(int j = 1; j <= i; j++) {
                dp[i][j] = 1 + p * dp[i-1][j] * Q(i) / Q(i+j+1)
                            + p * dp[i][j-1] * (Q(j) + j*(i+1)) / Q(i+j+1)
                            +(1-p) * dp[i-1][j] * (Q(i) + i*(j+1))/Q(i+j+1)
                            +(1-p) * dp[i][j-1] * Q(j) / Q(i+j+1); 

                if(i == j) continue;
                swap(i, j);
                dp[i][j] = 1 + p * dp[i-1][j] * Q(i) / Q(i+j+1)
                            + p * dp[i][j-1] * (Q(j) + j*(i+1)) / Q(i+j+1)
                            +(1-p) * dp[i-1][j] * (Q(i) + i*(j+1))/Q(i+j+1)
                            +(1-p) * dp[i][j-1] * Q(j) / Q(i+j+1); 

                swap(i, j);
            }
        }



        cout << "Case #" << ti << ": " << "\n"; 
        cout << fixed << setprecision(8);
        for(int i = 0; i < n; i++) {
            cout << dp[n-i-1][i] << "\n";
        }
    }

    return 0;
}