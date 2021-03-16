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

const int mod = 1e9+7;

vi dadj, uadj;
vb vis;

void dfs(int i) {
    if(vis[i]) return;
    vis[i] = true;

    for(int e = 0; e < 20; e++) {
        if((1 << e) & uadj[i]) dfs(e);
    }
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

    while(t--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;

        dadj.assign(20, 0);
        uadj.assign(20, 0);
        vis.assign(20, false);

        for(int i = 0; i < n; i++) {
            if(a[i] != b[i]) {
                dadj[a[i] - 'a'] |= (1 << (b[i] - 'a'));
                uadj[a[i] - 'a'] |= (1 << (b[i] - 'a'));
                uadj[b[i] - 'a'] |= (1 << (a[i] - 'a'));
            }
        }

        int ncomp = 0;

        for(int i = 0; i < 20; i++) {
            if(!vis[i]) {
                ncomp++;
                dfs(i);
            }
        }

        vb dp(1 << 20, 0);
        vb dp1(1 << 20, 0);
        int ldag = 0;

        dp[0] = true;
        dp1[0] = true;
        int msb = 1;

        for(int i = 1; i < (1 << 20); i++) {

            for(int j = 0; 1<<j <= i; j++) 
                if(i & (1 << j)) 
                    dp[i] = dp[i] || (dp[i ^ (1 << j)] && ((dadj[j] & i) == 0));

            if(dp[i]) ldag = max(ldag, __builtin_popcount(i));
        }

        
        int count = 2 * 20 - ldag - ncomp;
        cout << count << "\n";

    }
    return 0;
}
