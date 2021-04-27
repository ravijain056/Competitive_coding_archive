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
        freopen("capastaty_input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for(int ti = 1; ti <= t; ti++) {
        int n, k;
        cin >> n >> k;

        vl S(n), X(n), Y(n);

        ll a, b, c, d;

        for(int i = 0; i < k; i++) cin >> S[i];
        cin >> a >> b >> c >> d;
        for(int i = k; i < n; i++) S[i] = (a * S[i-2] + b * S[i-1] + c) % d;

        for(int i = 0; i < k; i++) cin >> X[i];
        cin >> a >> b >> c >> d;
        for(int i = k; i < n; i++) X[i] = (a * X[i-2] + b * X[i-1] + c) % d;

        for(int i = 0; i < k; i++) cin >> Y[i];
        cin >> a >> b >> c >> d;
        for(int i = k; i < n; i++) Y[i] = (a * Y[i-2] + b * Y[i-1] + c) % d;

        ll maxS = 0, sumS = 0, minS = 0, reqA = 0, reqS = 0;

        for(int i = 0; i < n; i++) {
            sumS += S[i];
            maxS += X[i] + Y[i];
            minS += X[i];
            if(S[i] > X[i] + Y[i]) reqS += S[i] - X[i] - Y[i];
            if(S[i] < X[i]) reqA += X[i] - S[i];
        }
        
        cout << "Case #" << ti << ": " ; 
        if(sumS > maxS || sumS < minS) cout << -1 << "\n";
        else {
            cout << max(reqS, reqA) << "\n";
        }
        
    }

    return 0;
}