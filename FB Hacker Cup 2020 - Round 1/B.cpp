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

ll n, m, k, s;
vl P, Q;
ll Ap, Bp, Cp, Dp;
ll Aq, Bq, Cq, Dq;

bool check(ll t) {
    auto itp = P.begin();
    auto itq = Q.begin();
    while(true) {
        if((*itp) <= (*itq)) {
            auto itp2 = itp;
            while(true) {
                itp2 = itp;
                itp = upper_bound(itp, P.end(), (*itp) + t);
                if(itp == P.end()) break;
                if(itp-1 != itp2) itp = itp-1;
                else break;
            }
            itq = upper_bound(itq, Q.end(), (*(itp-1)) + t);
        } else if((*itq) + t >= (*itp)){
            ll val = *itp;
            val = max(val, 2 * (*itq) + t - (*itp));
            val = max(val, ((*itq) + (*itp) + t) / 2);
            itq = upper_bound(itq, Q.end(), val);
            itp++;
        } else return false;

        if(itq == Q.end()) return true;
        if(itp == P.end()) return false;
    }
}

int main() {

    #ifdef LOCAL_DEV
        freopen("dislodging_logs_input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for(int ti = 1; ti <= t; ti++) {
        
        cin >> n >> m >> k >> s;

        P.resize(n);
        Q.resize(m);

        for(int i = 0; i < k; i++) cin >> P[i];
        cin >> Ap >> Bp >> Cp >> Dp;
        for(int i = k; i < n; i++) 
            P[i] = ((Ap * P[i-2] + Bp * P[i-1] + Cp) % Dp) + 1;

        for(int i = 0; i < k; i++) cin >> Q[i];
        cin >> Aq >> Bq >> Cq >> Dq;
        for(int i = k; i < m; i++) 
            Q[i] = ((Aq * Q[i-2] + Bq * Q[i-1] + Cq) % Dq) + 1;

        sort(P.begin(), P.end());
        sort(Q.begin(), Q.end());

        ll l = 0, r = 15e8;

        while(l != r) {
            ll mid = (l + r) / 2;
            if(check(mid)) {
                r = mid;
            } else {
                if(l == mid) l++;
                else l = mid;
            }
        }

        cout << "Case #" << ti << ": " << l << "\n"; 
    }

    return 0;
}