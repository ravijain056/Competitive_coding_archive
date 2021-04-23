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

int n;

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
        cin >> n;
        vl E(n), R(n);
        for(int i = 0; i < n; i++) cin >> E[i] >> R[i];

        ll tot = 0;
        for(int i = 0; i < n; i++) tot += E[i];

        priority_queue<pll, vpll, greater<pll>> heap;

        ll cnt = 0;
        ll lim = 0;

        ll sum = 0, mx = tot, mxcnt = 0;
        for(int i = 0; i < n; i++) {
            heap.push(mp(tot - E[i] - R[i], E[i]));
            sum += E[i];
            while(!heap.empty()) {
                if(heap.top().first < lim) {
                    lim += heap.top().second;
                    sum -= heap.top().second;
                    heap.pop();
                    cnt++;
                } else break;
            }
            ll ans = tot + sum - lim;
            if(ans > mx) {
                mx = ans;
                mxcnt = cnt;
            }
        }
        
        cout << "Case #" << ti << ": " ; 
        if(heap.empty()) {
            cout << mxcnt << " " << mx << "\n";
        } else {
            cout << cnt << " INDEFINITELY\n";
        }
        
        
    }

    return 0;
}