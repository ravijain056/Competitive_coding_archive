#include<bits/stdc++.h>
#include <queue>
#include <unordered_map>
#include <unordered_set>

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

ll powmod(ll x, ll y) {
    ll res = 1;
    x %= mod;
    y %= mod-1;
    if(y < 0) y += mod-1;
    while(y > 0) {
        if(y & 1) res = (res * x) % mod;
        y >>= 1;
        x = (x*x) % mod;
    }
    return res;
}

vb isPrime;
vl primes;

void fillPrimes(int n) {
    isPrime.assign(n + 1, true);
    for(ll i = 2; i <= n; i++) {
        if(isPrime[i]) primes.pb(i);
        for(ll j : primes) {
            if(i*j > n) break;
            isPrime[i*j] = false;
        }
    }
}

vl seg;
int seg_len;

void build_seg(vl A, int n) {
    seg.resize(2 * n);
    seg_len = n;
    for(int i = n ;  i < 2*n; i++) seg[i] = A[i-n];
    for(int i = n-1; i > 0; --i) seg[i] = (seg[i<<1] + seg[i << 1|1]) % mod;
}

void update_seg(int i, ll val) {
    int n = seg_len;
    for(seg[i += n] = val; i > 1; i >>= 1) seg[i>>1] = (seg[i] + seg[i^1]) % mod;
}

ll query_seg(int l, int r) {
    ll res = 0;
    int n = seg_len;
    for(l+=n, r+=n; l < r; l >>= 1, r >>= 1) {
        if(l&1) res += seg[l++];
        if(r&1) res += seg[--r];
        res %= mod;
    }
    return res;
}

vi par;
vector<unordered_map<int, pii>> sums;
unordered_set<int> leafs;
vpii A;

int main() {

    #ifdef LOCAL_DEV
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(6) << fixed;

    int n;
    cin >> n;

/*    vi A(n);
    int maxi = -1, maxval = 0;
    for(int i = 0; i < n; i++) {
        cin >> A[i];
        if(A[i] > maxval) {
            maxval = A[i];
            maxi = i;
        }
    }

    for(int i = 0; i < n; i++) {
        if(i != maxi) cout << i+1 << " " << maxi+1 << "\n";
    }
*/

    A.resize(n);

    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        A[i] = mp(val, i + 1);
    }

    sort(A.rbegin(), A.rend());

/*    int i = 0;
    while(i < n) {
        int l = i * 2 + 1;
        int r = i * 2 + 2;
        if(l < n) cout << A[i].second << " " << A[l].second << "\n";
        if(r < n) cout << A[i].second << " " << A[r].second << "\n";
        i++;
    }
*/

/*    queue<int> nodes;
    nodes.push(0);    
    nodes.push(0);    
    
    int i = 1;
    while(i < n) {
        vi nodes2;
        while(!nodes.empty()) {
            int cur = nodes.front();
            nodes.pop();
            cout << A[i].second << " " << A[cur].second << "\n";
            nodes2.pb(i);
            i++;
            if(i >= n) break;
        }
        for(int a : nodes2) nodes.push(a);
        for(int a : nodes2) nodes.push(a);
        nodes2.clear();
    }
*/

    par.resize(n );
    sums.resize(n + 1);
    leafs.clear();
    
    par[0] = -1;
    par[1] = 0;
    sums[0].insert(mp(0, mp(A[0].first, 1)));
    sums[0].insert(mp(1, mp(A[1].first + A[0].first, 2)));
    //sums[1].insert(mp(1, mp(A[1].first, 0)));
    leafs.insert(0);
    for(int i = 2; i < n; i++) {
        int maxj = -1, maxchange = 0;
        for(int j = 0; j < i; j++) {
            int curchange = 0;
            int node = j;
            int curtotal = A[i].first;
            int curlen = 0;
            while(node != -1) {
                for(pair<int, pii> c : sums[node]) {
                    if(c.first == j) continue;
                    if(leafs.find(j) != leafs.end()) 
                        curchange -= (c.second.first + curtotal - A[i].first) * (c.second.second + curlen - 1);
                    curchange += (c.second.first + curtotal) * (c.second.second + curlen);
                }
                curtotal += A[node].first;
                curlen++;
                node = par[node];
            }
            if(curchange > maxchange) {
                maxchange = curchange;
                maxj = j;
            }
        }

        leafs.insert(i);
        int node = maxj;
        int curtotal = A[i].first;
        int curlen = 1;
        while(node != -1) {
            curtotal += A[node].first;
            curlen++;
            if(leafs.find(maxj) != leafs.end())
                sums[node].erase(maxj);
            sums[node].insert(mp(i, mp(curtotal, curlen)));
            node = par[node];
        }
        if(leafs.find(maxj) != leafs.end()) leafs.erase(maxj);
        par[i] = maxj;
    }

    for(int i = 1; i < n; i++) 
        cout << A[i].second << " " << A[par[i]].second << "\n";
    
    return 0;
}
