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
#define height second.first
#define type second.second
#define X first.first
#define Y first.second
const int mod = 1e9+7;

int main() {

    #ifdef LOCAL_DEV
        freopen("perimetric_chapter_3_input.txt", "r", stdin);
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

        set<pair<pll, pll> > seg;
        seg.insert(mp(mp(L[0], H[0]), mp(H[0], 0)));
        seg.insert(mp(mp(L[0] + W[0], H[0]), mp(H[0], 1)));

        for(int i = 1; i < n; i++) {
            P[i] = P[i-1];
            auto it = seg.lower_bound(mp(mp(L[i], -1), mp(-1, -1)));

            ll prevR = L[i];
            pair<pll, pll> curseg;
            if(it == seg.end() || (*it).type == 0) {
                P[i] += H[i];
                curseg = mp(mp(L[i], H[i]), mp(H[i], 0));
            } else {
                auto it2 = prev(it);
                ll subh = 0;
                if((*it2).type == 3) {
                    subh = (*it2).Y - (*it2).height;
                } else {
                    subh = (*it2).Y;
                }
                P[i] += H[i] - subh;
                curseg = mp(mp(L[i], H[i]), mp(H[i] - subh, 2));
            }
            
            while(it != seg.end() && (*it).X <= L[i] + W[i]) {
                P[i] -= (*it).height;
                if((*it).type == 0) P[i] += 2 * ((*it).X - prevR);
                else prevR = (*it).X;
                it = seg.erase(it);
            }

            seg.insert(curseg);

            if(it == seg.end() || (*it).type == 0) {
                P[i] += H[i];
                P[i] += 2 * (L[i] + W[i] - prevR);
                seg.insert(it, mp(mp(L[i] + W[i], H[i]), mp(H[i], 1)));
            } else if((*it).type == 1 || (*it).type == 3) {
                P[i] += H[i] - (*it).Y;
                seg.insert(it, mp(mp(L[i] + W[i], H[i]), mp(H[i] - (*it).Y, 3)));
            } else {
                P[i] += H[i] - (*it).Y + (*it).height;
                seg.insert(it, mp(mp(L[i] + W[i], H[i]), mp(H[i] - (*it).Y + (*it).height, 3)));
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