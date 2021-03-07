#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define mp make_pair


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int t;
    cin >> t;

    while(t--) {
        ll n, m;
        cin >> n >> m;
        ll maxb = 1000000001;
        vector<pii> ab(m);
        for(int i = 0; i < m; i++) {
            ll ai, bi;
            cin >> ai >> bi;
            ab[i] = mp(ai, bi);
        }

        sort(ab.begin(), ab.end(), greater<pii>());

        vector<ll> a_sum(m);
        a_sum[0] = ab[0].first;
        for(int i = 1; i < m; i++) a_sum[i] = a_sum[i-1] + ab[i].first;

        ll maxtot = -1;
        if(m >= n) maxtot = a_sum[n-1];

        for(int i = 0; i < m; i++) {
            int l = lower_bound(ab.begin(), ab.end(), mp(ab[i].second, maxb),
                                greater<pii>()) - ab.begin();
            if(l >= n) continue;
            ll curtot = 0;
            if(l > 0) curtot = a_sum[l-1];
            if(l > i) curtot += (n-l) * ab[i].second;
            else curtot += ab[i].first + (n-l-1) * ab[i].second;
            maxtot = max(maxtot, curtot);
        }
        
        cout << maxtot << "\n";
    }
    return 0;
}