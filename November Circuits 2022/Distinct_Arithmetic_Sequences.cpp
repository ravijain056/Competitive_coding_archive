#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
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

ll powmod(ll x, ll y) {
    ll res = 1;
    x %= mod;
    y %= mod-1;
    while(y > 0) {
        if(y & 1) res = (res * x) % mod;
        y >>= 1;
        x = (x*x) % mod;
    }
    return res;
}


int main() {

    #ifdef LOCAL_DEV
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(6) << fixed;

    int t;
    cin >> t;

    for(int ti = 1; ti <= t; ti++) {
        int m, n;
        cin >> m >> n;
        vi nums(2*m + 1, 0);

        for(int i = 0; i < m+n; i++) {
            int a;
            cin >> a;
            nums[a+m]++;
        }
        
        if(m == 2) {
            int distinct_count = 0, ans = 0;
            for(int i = 0; i <= 2* m; i++) {
                if(nums[i] >= m) ans++;
                if(nums[i] > 0) distinct_count++;
            }
            ans += (distinct_count * (distinct_count - 1));
            cout << ans << "\n";
            continue;
        }

        int ans = 0, cur = 0;
        for(int i = 0; i <= 2*m; i++) {
            if(nums[i] >= m) ans++;
            if(nums[i] > 0) cur++;
            else cur = 0;
            if(cur >= m) ans += 2;
        }

        for(int i = 0; i < 3; i++) {
            for(int j = i; j <= 2*m - 2 + i; j+=2) {
                if(nums[j] == 0) break;
                if(j == 2*m - 2 + i) ans += 2;
            }
        }

        if(m == 3) if(nums[0] && nums[3] && nums[6]) ans += 2;

        cout << ans << "\n";
    }

    return 0;
}
