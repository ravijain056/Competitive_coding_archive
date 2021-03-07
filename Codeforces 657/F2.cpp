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

const int MAXN = 2e6;

int n, m, q;
vector<set<int> > js(MAXN);
vi mx(MAXN), mn(MAXN), fl(MAXN), idx(MAXN);

void build(int i, int l, int r) {
    mx[i] = 0;
    mn[i] = 2 * m + 1;
    fl[i] = 1;
    if(l == r) {
        idx[l] = i;
    } else {
        int mid = (l+r)>>1;
        build(i<<1, l, mid);
        build(i<<1|1, mid+1, r);
    }
}

void upd(int x, int y) {
    int i = idx[x], l, r;
    if(x & 1) 
        if(js[x].size()) mn[i] = *js[x].begin();
        else mn[i] = 2*m + 1;
    else 
        if(js[x].size()) mx[i] = *js[x].rbegin();
        else mx[i] = 0;
    
    while(i >>= 1) {
        l = i << 1;
        r = l | 1;
        mn[i] = min(mn[l], mn[r]);
        mx[i] = max(mx[l], mx[r]);
        fl[i] = fl[l] && fl[r] && (mn[l] > mx[r]);
    }
 }

int main() {

    #ifdef LOCAL_DEV
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> q;

    build(1, 1, n << 1);

    while(q--) {
        int x, y;
        cin >> x >> y;
        
        auto it = js[x].find(y);
        if(it != js[x].end()) js[x].erase(it);
        else js[x].insert(y);
        
        upd(x, y);

        if(fl[1]) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
