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
        freopen("perimetric_chapter_2_input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for(int ti = 1; ti <= t; ti++) {
        ll n, k;
        cin >> n >> k;

        vl L(n), W(n), H(n), P(n);
        ll Al, Bl, Cl, Dl;
        ll Aw, Bw, Cw, Dw;
        ll Ah, Bh, Ch, Dh;

        for(int i = 0; i < k; i++) cin >> L[i];
        cin >> Al >> Bl >> Cl >> Dl;
        
        for(int i = 0; i < k; i++) cin >> W[i];
        cin >> Aw >> Bw >> Cw >> Dw;
        
        for(int i = 0; i < k; i++) cin >> H[i];
        cin >> Ah >> Bh >> Ch >> Dh;

        for(int i = k; i < n; i++) {
            L[i] = ((Al * L[i-2] + Bl * L[i-1] + Cl) % Dl) + 1;
            W[i] = ((Aw * W[i-2] + Bw * W[i-1] + Cw) % Dw) + 1;
            H[i] = ((Ah * H[i-2] + Bh * H[i-1] + Ch) % Dh) + 1;
        }

        P[0] = (2 * W[0] + 2 * H[0]) % mod;

        set<pll> seg;
        seg.insert(mp(L[0], 0));
        seg.insert(mp(L[0] + W[0], 1));

        for(int i = 1; i < n; i++) {
            P[i] = P[i-1];

            auto it = seg.lower_bound(mp(L[i], -1));
            ll prevR = L[i];
            if(it == seg.end() || (*it).second == 0) {
                P[i] += H[i];
                seg.insert(it, mp(L[i], 0));
            }

            while(it != seg.end() && (*it).first <= L[i] + W[i]) {
                P[i] -= H[i];
                if((*it).second == 0) P[i] += 2 * ((*it).first - prevR);
                else prevR = (*it).first;
                if((*it) == mp(L[i], 0LL)) it++;
                else it = seg.erase(it);
            }

            if(it == seg.end() || (*it).second == 0) {
                P[i] += H[i];
                P[i] += 2 * (L[i] + W[i] - prevR);
                seg.insert(it, mp(L[i] + W[i], 1));
            }

        }

        ll mulp = P[0];
        for(int i = 1; i < n; i++) {
            P[i] %= mod;
            mulp = (mulp * P[i]) % mod;
        }

        cout << "Case #" << ti << ": " << mulp << "\n"; 
    }

    return 0;
}