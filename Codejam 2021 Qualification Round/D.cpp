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

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, q;
    cin >> t >> n >> q;

    for(int ti = 1; ti <= t; ti++) {
        vi ans;
        ans.pb(1);
        ans.pb(2);
        
        for(int i = 3; i <= n; i++) {
            int l = 0, r = ans.size() - 1;
            while(l <= r) {
                if(l == r) {
                    if(l == 0) r++;
                    else l--;
                }
                int s = r - l + 1;
                int x1 = l + (s / 3);
                int x2 = l + (s * 2 / 3);
                cout << ans[x1] << " " << ans[x2] << " " << i << "\n" << flush;

                int v;
                cin >> v;
                if(v == -1) exit(1);
                if(v == ans[x1]) {
                    r = x1 - 1;
                } else if(v == ans[x2]) {
                    l = x2 + 1;
                } else {
                    l = x1 + 1;
                    r = x2 - 1;
                }
            }
            ans.insert(ans.begin() + l, i);
        }

        for(int o : ans) cout << o << " ";
        cout << "\n" << flush;

        int v;
        cin >> v;
        if(v == -1) exit(1);
    }

    return 0;
}
