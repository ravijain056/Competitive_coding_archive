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

ll pown(ll x, int y) {
    ll res = 1;
    while(y) {
        if(y & 1) res *= x;
        x *= x;
        y >>= 1;
    }
    return res;
}

ll getsum(ll l, int k) {
    if(l == 0) return 1;
    vl L;
    ll n = ceil(10. / k);
    while(l) {
        L.push_back(l % 10);
        l /= 10;
    }
    ll res = 0;
    for(int i = L.size() - 1; i >= 0; i--) {
        ll curn = ceil((0.+ L[i]) /  k);
        res += pown(n, i) * curn;
        if(L[i] % k != 0) break;
        if(i == 0) res++;
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
        ll l, r, k;
        cin >> l >> r >> k;
        cout << getsum(r, k) - getsum(l-1, k) << "\n";
    }

    return 0;
}