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

int n, q;
vpll segQ;
vl Qt;

pll query(int l, int r) {
    if(l < 0) l = 0;
    if(r > n) r = n;
    pll res = mp(-1, 0);
    for(l += n, r += n; l < r; l >>= 1, r >>=1) {
        if(l&1) res = max(res, segQ[l++]);
        if(r&1) res = max(res, segQ[--r]);
    }
    return res;
}

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
        cin >> n >> q;
        segQ.resize(2*n);

        for(int i = 0; i < n; i++) {
            ll Q;
            cin >> Q;
            segQ[n+i] = mp(Q, i+1);
        }
        
        Qt.resize(n+1);
        for(int i = 1; i <= n; i++) cin >> Qt[i];

        for(int i = n-1; i > 0; i--) segQ[i] = max(segQ[i<<1], segQ[i<<1|1]);
        
        while(q--) {
            int type;
            cin >> type;
            if(type == 1) {
                int l, r, qt;
                cin >> l >> r >> qt;
                pll ret = query(l-1, r);
                Qt[ret.second] += qt;
            } else {
                int v, i, qt, thr;
                cin >> v >> i >> qt >> thr;
                pll ret = query(i-v-1, i+v);
                if(ret.first >= thr && Qt[ret.second] >= qt) {
                    Qt[ret.second] -= qt;
                    cout << ret.second << "\n";
                } else {
                    cout << "No purchase\n";
                }
            }
        }

    }

    return 0;
}