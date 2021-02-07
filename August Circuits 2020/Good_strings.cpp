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

int n;
string s;
vi v, nxt;
vpii items;
unordered_map<int, pii> item_val;
vector<pair<pii, int> > brack_val;
map<pii, int> dp;

int getdp(int v, int n) {
    if(v < 0) return INT_MAX/2;
    if(n == -1) return 0;
    pii cur = mp(v, n);
    if(dp.find(cur) != dp.end()) return dp[cur];

    int r = items[n].first, g = items[n].second;
    if(v < r && v < g) return INT_MAX/2;
    dp[cur] = min(getdp(v-r, n-1) + g, getdp(v-g, n-1) + r);
    return dp[cur];
}

int main() {

    #ifdef LOCAL_DEV
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin >> s;

    nxt.resize(n);

    int cnt1 = 0, cnt2 = 0;

    for(char c : s) {
        if(c == '#') cnt1++;
        if(c == '(') cnt2++;
    }

    for(int i = 0; i < cnt1; i++) {
        int l, v;
        cin >> l >> v;
        l--;
        item_val[l] = mp(v, 0);
        nxt[l] = l+1;
    }

    for(int i = 0; i < cnt2; i++) {
        int l, r, v;
        cin >> l >> r >> v;
        l--; r--;
        brack_val.push_back(mp(mp(l, r), v));
        nxt[l] = r+1;
    }

    sort(brack_val.begin(), brack_val.end());
    
    bool pos = true;
    while(cnt2--) {
        items.clear();
        int start = brack_val[cnt2].first.first;
        int end = brack_val[cnt2].first.second;
        int i = start + 1;

        while(i < end) {
            items.push_back(item_val[i]);
            i = nxt[i];
        }

        int v = brack_val[cnt2].second;
        dp.clear();
        int dpres = getdp(v, items.size() - 1);
        if(dpres >= INT_MAX/2) {
            pos = false;
            break;
        }
        item_val[start] = mp(v, dpres);
    }

    if(pos) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}