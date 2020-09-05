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


int solve(vi& locations, int start, int finish, int fuel) {
    const int mod = 1e9+7;
    int n = locations.size();
    vvi dp;
    dp.assign(n, vi(fuel+1, 0));
    dp[finish][0] = 1;
    for(int f = 1; f <= fuel; f++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                if(abs(locations[i] - locations[j]) > f) continue;
                dp[i][f] += dp[j][f-abs(locations[i] - locations[j])];
                dp[i][f] %= mod;
            }
        }
    }
    int ans = 0;
    for(int f= 0; f <= fuel; f++) {
        ans += dp[start][f];
        ans %= mod;
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
        int n;
        cin >> n;
        vi A(n);
        for(int i = 0; i < n; i++) cin >> A[i];
        int start, end, fuel;
        cin >> start >> end >> fuel;
        cout << solve(A, start, end, fuel) << "\n";
        
        //cout << "Case #" << ti << ": " ; 
    }

    return 0;
}