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
        int n, a, b;
        cin >> n >> a >> b;

        vi req(n);
        for(int i = 0; i < n; i++) cin >> req[i];

        deque<ll> mine, mine2;
        mine.pb(1);
        for(int i = 0; i < n+30; i++) mine.pb(0);
        
        while (!req.empty() && req.back() == 0) req.pop_back();
        
        reverse(req.begin(), req.end());
        n = req.size();
        int ans = n;

        while(true) {
            bool pos = true;
            mine2 = mine;
            for(int i = 0; i < n; i++) {
                if(mine[i] < req[i]) {
                    pos = false;
                    break;
                } else {
                    int diff = mine[i] - req[i];
                    mine[i+a] += diff;
                    mine[i+b] += diff;
                    mine[i] -= diff;
                }
            }
            if(pos) break;
            mine = mine2;
            ans++;
            mine[a] += mine[0];
            mine[b] += mine[0];
            mine.pop_front();
            mine.pb(0);
            if(ans > 1e4) {
                ans = -1;
                break;
            }
        }

        cout << "Case #" << ti << ": " ;
        if(ans == -1) cout << "IMPOSSIBLE\n";
        else cout << ans << "\n"; 
    }

    return 0;
}
