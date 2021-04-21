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
        int n, k;
        cin >> n >> k;
        vpii intervals(n);
        for(int i = 0; i < n; i++) cin >> intervals[i].first >> intervals[i].second;
        sort(intervals.begin(), intervals.end());

        int curt = intervals[0].first + k;
        int cnt = 1;
        int i = 0;
        while(i < n) {
            if(curt <= intervals[i].first) {
                cnt++;
                curt = intervals[i].first + k;
            } else if(intervals[i].second <= curt) i++;
            else {
                int dep = ((intervals[i].second - curt + k - 1) / k);
                cnt += dep;
                curt += k * dep;
            }
        }
        cout << "Case #" << ti << ": " << cnt << "\n"; 
    }

    return 0;
}