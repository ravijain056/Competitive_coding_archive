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

int n, m;
vl addseg, maxseg, A, lazy, eleseg;

void build(int i, int l, int r) {
    if(l == r) {
        addseg[i] = A[l-1];
        maxseg[i] = A[l-1];
        eleseg[i] = A[l-1];
    } else {
        int mid = (l+r)/2;
        build(2*i, l, mid);
        build(2*i+1, mid+1, r);
        addseg[i] = addseg[i<<1] + addseg[i<<1|1];
        maxseg[i] = max(maxseg[i<<1], maxseg[i<<1|1]);
        if(eleseg[i<<1] == eleseg[i<<1|1]) eleseg[i] = eleseg[i<<1];
        else eleseg[i] == -1;
    }
}

void update(int i, int l, int r, int tl, int tr, ll val) {
    
    if(l > r || l > tr || r < tl) return;

    if(l == r) {
        addseg[i] = val;
        maxseg[i] = val;
        eleseg[i] = val;
        return;
    }

    if(tl == l && tr == r) {
        lazy[i] = val;
        addseg[i] = val * (r-l+1);
        maxseg[i] = val;
        eleseg[i] = val;
        return;
    }
    int mid = (l+r)/2;
    if(lazy[i] > 0) {
        update(i<<1, l, mid, l, mid, lazy[i]);
        update(i<<1|1, mid+1, r, mid+1, r, lazy[i]);
        lazy[i] = -1;
    }

    update(i<<1, l, mid, tl, min(mid, tr), val);
    update(i<<1|1, mid+1, r, max(mid+1, tl), tr, val);
    addseg[i] = addseg[i<<1] + addseg[i<<1|1];
    maxseg[i] = max(maxseg[i<<1], maxseg[i<<1|1]);
    if(eleseg[i<<1] == eleseg[i<<1|1]) eleseg[i] = eleseg[i<<1];
    else eleseg[i] = -1;
}

void update2(int i, int l, int r, int tl, int tr, ll val) {
    if(l > r || l > tr || r < tl) return;

    if(l == r) {
        val = __gcd(val, eleseg[i]);
        addseg[i] = val;
        maxseg[i] = val;
        eleseg[i] = val;
        return;
    }

    if(tl == l && tr == r && eleseg[i] != -1) {
        val = __gcd(val, eleseg[i]);
        lazy[i] = val;
        addseg[i] = val * (r-l+1);
        maxseg[i] = val;
        eleseg[i] = val;
        return;
    }

    int mid = (l+r)/2;

    if(lazy[i] > 0) {
        update(i<<1, l, mid, l, mid, lazy[i]);
        update(i<<1|1, mid+1, r, mid+1, r, lazy[i]);
        lazy[i] = -1;
    }

    update2(i<<1, l, mid, tl, min(tr, mid), val);
    update2(i<<1|1, mid+1, r, max(tl, mid+1), tr, val);
    addseg[i] = addseg[i<<1] + addseg[i<<1|1];
    maxseg[i] = max(maxseg[i<<1], maxseg[i<<1|1]);
    if(eleseg[i<<1] == eleseg[i<<1|1]) eleseg[i] = eleseg[i<<1];
    else eleseg[i] = -1;
}

ll queryAdd(int i, int l, int r, int tl, int tr) {
    
    if(l > r || l > tr || r < tl) return 0;

    if(l == tl && r == tr) {
        return addseg[i];
    }
    
    int mid = (l+r)/2;
    if(lazy[i] > 0) {
        update(i<<1, l, mid, l, mid, lazy[i]);
        update(i<<1|1, mid+1, r, mid+1, r, lazy[i]);
        lazy[i] = -1;
    }

    return queryAdd(i<<1, l, mid, tl, min(mid, tr)) + 
            queryAdd(i<<1|1, mid+1, r, max(tl, mid+1), tr);
}

ll queryMax(int i, int l, int r, int tl, int tr) {
    if(l > r || l > tr || r < tl) return 0;

    if(l == tl && r == tr) {
        return maxseg[i];
    }
    
    int mid = (l+r)/2;
    if(lazy[i] > 0) {
        update(i<<1, l, mid, l, mid, lazy[i]);
        update(i<<1|1, mid+1, r, mid+1, r, lazy[i]);
        lazy[i] = -1;
    }

    return max(queryMax(i<<1, l, mid, tl, min(tr, mid)),
            queryMax(i<<1|1, mid+1, r, max(tl, mid+1), tr));

}

int main() {

    #ifdef LOCAL_DEV
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    A.resize(n);
    addseg.resize(4*n);
    maxseg.resize(4*n);
    lazy.assign(4*n, -1);
    eleseg.assign(4*n, -1);

    for(int i = 0; i < n; i++) cin >> A[i];
    build(1, 1, n);

    while(m--) {
        int type, l, r, val;
        cin >> type >> l >> r;
        if(type == 1) {
            cin >> val;
            update(1, 1, n, l, r, val);
        } else if(type == 2) {
            cin >> val;
            update2(1, 1, n, l, r, val);
        } else if(type == 3) {
            cout << queryMax(1, 1, n, l, r) << "\n";
        } else {
            cout << queryAdd(1, 1, n, l, r) << "\n";
        }
    }
    
    return 0;
}