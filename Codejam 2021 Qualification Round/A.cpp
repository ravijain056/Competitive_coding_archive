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
        int n;
        cin >> n;
        vi L(n);

        for(int i = 0; i < n; i++) cin >> L[i];

        int ans = 0;

        for(int i = 0; i < n-1; i++) {
            int j = i;
            while(L[j] != i+1) j++;
            reverse(L.begin() + i, L.begin() + j + 1);
            ans += j-i+1;
        }
        
        cout << "Case #" << ti << ": " << ans << "\n"; 
    }

    return 0;
}
