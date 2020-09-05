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

    int n, m, k;
    cin >> n >> m >> k;

    vi A(n), B(n), C(n);

    for(int i = 0; i < n; i++) {
        cin >> A[i] >> B[i] >> C[i];
        A[i] %= m;
        B[i] %= m;
        C[i] %= m;
    }

    int xl, xr, yl, yr, zl, zr;
    cin >> xl >> xr >> yl >> yr >> zl >> zr;

    bool pos = false;
    for(ll x = xl; x <= min(xl+15, xr); x++) {
        for(ll y = yl; y <= min(yl+15, yr); y++) {
            for(ll z = zl; z <= min(zl+15, zr); z++) {
                int cnt = 0;
                for(int i = 0; i < n; i++) {
                    if((A[i]*x + B[i]*y - C[i]*z + m * z) % m == 0) cnt++;
                }               
                if(cnt == k) {
                    pos = true;
                    cout << x << " " << y << " " << z;
                    break;
                }
            }
            if(pos) break;
        }
        if(pos) break;
    }
    if(!pos) cout << -1;

    return 0;
}