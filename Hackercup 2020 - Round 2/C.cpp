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

int main() {

    #ifdef LOCAL_DEV
        freopen("circular_circles_input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for(int ti = 1; ti <= t; ti++) {
        ll n, m, e, k;
        cin >> n >> m >> e >> k;
        
        vl w(n*m+n, 1);
        vl X(n), Y(n), I(e), W(e);
        ll a, b, c;

        for(int i = 0; i < k; i++) cin >> X[i];
        cin >> a >> b >> c;
        for(int i = k; i < n; i++) X[i] = (a * X[i-2] + b * X[i-1] + c) % m;

        for(int i = 0; i < k; i++) cin >> Y[i];
        cin >> a >> b >> c;
        for(int i = k; i < n; i++) Y[i] = (a * Y[i-2] + b * Y[i-1] + c) % m;


        for(int i = 0; i < k; i++) cin >> I[i];
        cin >> a >> b >> c;
        for(int i = k; i < e; i++) I[i] = (a * I[i-2] + b * I[i-1] + c) % (n*m + n);

        for(int i = 0; i < k; i++) cin >> W[i];
        cin >> a >> b >> c;
        for(int i = k; i < e; i++) W[i] = (a * W[i-2] + b * W[i-1] + c) % ((int)1e9);

        ll tot = n*m + n;

        vector<vector<multiset<ll> > > sets(n, vector<multiset<ll> >(3));
        multiset<ll> inner;
        vvi setdiv(n, vi(m));
        vl R(n), D(n);

        for(int i = 0; i < n; i++) {
            int cur = 0;
            for(int j = 0; j < m; j++) {
                sets[i][2].insert(1);
                if(X[i] == j) cur ^= 1;
                if(Y[i] == j) cur ^= 1; 
                sets[i][cur].insert(1);
                setdiv[i][j] = cur;
            }
            R[i] = *sets[i][2].rbegin();
            D[i] = 0;
            if(!sets[i][0].empty()) D[i] += *sets[i][0].rbegin();
            if(!sets[i][1].empty()) D[i] += *sets[i][1].rbegin();
            D[i] -= R[i];
            inner.insert(D[i]);
            tot -= R[i];
        }

        for(int i = 0; i < n; i++) inner.insert(1);
        
        tot -= *inner.rbegin();

        ll ans = 1;

        for(int i = 0; i < e; i++) {
            tot -= w[I[i]];
            tot += W[i];

            tot += *inner.rbegin();
            if(I[i] >= n * m) {
                inner.erase(inner.find(w[I[i]]));
                inner.insert(W[i]);
                tot -= *inner.rbegin();
            } else {
                int c = I[i] / m;
                int d = I[i] % m;
                tot += R[c];
                inner.erase(inner.find(D[c]));
                sets[c][2].erase(sets[c][2].find(w[I[i]]));
                sets[c][setdiv[c][d]].erase(sets[c][setdiv[c][d]].find(w[I[i]]));

                sets[c][2].insert(W[i]);
                sets[c][setdiv[c][d]].insert(W[i]);
                R[c] = *sets[c][2].rbegin();

                D[c] = 0;
                if(!sets[c][0].empty()) D[c] += *sets[c][0].rbegin();
                if(!sets[c][1].empty()) D[c] += *sets[c][1].rbegin();
                D[c] -= R[c];
                inner.insert(D[c]);

                tot -= R[c];
                tot -= *inner.rbegin();
            }

            w[I[i]] = W[i];
            ans = ans * (tot % mod) % mod;
        }
        cout << "Case #" << ti << ": " << ans << "\n"; 
    }

    return 0;
}