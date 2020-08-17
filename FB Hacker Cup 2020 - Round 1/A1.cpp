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
const int mod = 1e9+7;

int main() {

    #ifdef LOCAL_DEV
        freopen("perimetric_chapter_1_input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for(int ti = 1; ti <= t; ti++) {
        ll n, k, w;
        cin >> n >> k >> w;

        vl L(n), H(n);
        ll Al, Bl, Cl, Dl;
        ll Ah, Bh, Ch, Dh;

        for(int i = 0; i < k; i++) cin >> L[i];
        cin >> Al >> Bl >> Cl >> Dl;
        
        for(int i = 0; i < k; i++) cin >> H[i];
        cin >> Ah >> Bh >> Ch >> Dh;

        ll curp = (2 * w + 2 * H[0]) % mod;
        ll mulp = curp;
        for(int i = 1; i < n; i++) {
            if(i >= k) {
                H[i] = ((Ah * H[i-2] + Bh * H[i-1] + Ch) % Dh) + 1;
                L[i] = ((Al * L[i-2] + Bl * L[i-1] + Cl) % Dl) + 1;
            }

            curp += 2 * min(w, (L[i] - L[i-1]));
            
            if(L[i-1] + w >= L[i]) {
                ll maxH = H[i-1];
                if(i > 1) {
                    int j = i-2;
                    while(L[j] + w >= L[i]) {
                        maxH = max(maxH, H[j]);
                        if(j == 0) break;
                        j--;
                    }
                }
                curp += 2 * max(0LL, H[i] - maxH);
            } else {
                curp += 2 * H[i];
            }
            curp %= mod;
            mulp = (mulp * curp) % mod;
        }

        cout << "Case #" << ti << ": " << mulp << "\n"; 
    }

    return 0;
}