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
        vi arr(2*n);
        for(int i = 0; i < 2*n; i++) cin >> arr[i];

        vpii mx(2*n);
        
        mx[0] = mp(arr[0], 0);

        for(int i = 1; i < 2 *n; i++) {
            if(arr[i] > mx[i-1].first) mx[i] = mp(arr[i], i);
            else mx[i] = mx[i-1];
        }
        
        vi sets;

        int j = 2*n-1;
        while(j >= 0) {
            sets.pb(j - mx[j].second + 1);
            j = mx[j].second - 1;
        }

        if(sets[0] == n) {
            cout << "YES\n";
            continue;
        }

        vvi dp(n, vi(sets.size(), 0));

        deque<pii> q;

        q.pb(mp(0, 0));
        if(sets[0] < n) q.pb(mp(sets[0], 0));

        bool poss = false;

        while(!q.empty()) {
            pii cur = q.front();
            q.pop_front();
            if(dp[cur.first][cur.second]) continue;

            dp[cur.first][cur.second] = 1;
            cur.second += 1;
            if(cur.second == sets.size()) continue;
            
            q.pb(cur);
            cur.first += sets[cur.second];
            if(cur.first == n) {
                poss = true;
                break;
            }
            if(cur.first > n) continue;
            q.pb(cur);
        }

        if(poss)cout << "YES\n";
        else cout << "NO\n";

    }

    return 0;
}
