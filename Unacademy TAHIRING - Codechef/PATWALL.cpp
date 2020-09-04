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

    int n;
    ll s;
    cin >> n >> s;
    
    vl e(n);
    for(int i = 0; i < n; i++) cin >> e[i];

    ll l = 0, r = 0;
    ll ans = 0;
    ll sume = 0, sumi = 0;
    while(r < n) {
        sume += e[r];
        r++;
        sumi += r;
        ll curs = sume + (r-l) * sumi;
        while(curs > s) {
            sume -= e[l];
            l++;
            sumi -= l;
            curs = sume + (r-l) * sumi;
        }
        ans = max(ans, r-l);
    }

    cout << ans;

    return 0;
}