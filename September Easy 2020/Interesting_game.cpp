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

    int t;
    cin >> t;

    for(int ti = 1; ti <= t; ti++) {
        int n;
        cin >> n;

        vi A(n), B(n);
        vpii BA(n);

        for(int i = 0; i < n; i++) cin >> A[i];
        for(int i = 0; i < n; i++) cin >> B[i];
        for(int i = 0; i < n; i++) BA[i] = mp(B[i], A[i] + B[i]);

        sort(BA.begin(), BA.end());

        priority_queue<int> heap;
        ll ans = BA[0].second;
        for(int i = 1; i < n-1; i+=2) {
            heap.push(BA[i].second);
            heap.push(BA[i+1].second);
            ans += heap.top();
            heap.pop();
        }
        for(int i = 0; i < n; i++) ans -= B[i];
        
        cout << ans << "\n";

    }

    return 0;
}