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

vi is, js, ans;

bool check(int cur) {

    vpii L, R;

    for(int i = 0; i <= cur; i++) {
        int x = is[i], y = js[i];
        if(x & 1) { // L-square
            x++;
            y++;
            x /= 2;
            y /= 2;
            L.pb(mp(x, y));
        } else {    // R-square
            x /= 2;
            y /= 2;
            R.pb(mp(x, y));
        }
    }
    
    sort(L.begin(), L.end());
    sort(R.begin(), R.end());

    int li = 0, miny = 200001;
    for(pii r : R) {
        while(li < L.size() && r.first >= L[li].first) 
            miny = min(miny, L[li++].second);
        
        if(r.second >= miny) return false;
    }

    return true;
}

void bin_search(int start, int end) {
    if(start > end) return;
    int mid = (start + end)/2;
    if(check(mid)) {
        ans[mid] = 1;
        bin_search(mid+1, end);
    } else {
        ans[mid] = 0;
        bin_search(start, mid-1);
    }
}

int main() {

    #ifdef LOCAL_DEV
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;
    is.resize(q);
    js.resize(q);
    ans.assign(q, 1);

    for(int ti = 0; ti < q; ti++) cin >> is[ti] >> js[ti];
    
    bin_search(0, q-1);

    bool out = true;
    for(int a : ans) {
        if(a == 0) out = false;
        if(out) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
