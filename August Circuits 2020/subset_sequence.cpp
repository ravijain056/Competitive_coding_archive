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

int main() {

    #ifdef LOCAL_DEV
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    vl pow3n(42);
    pow3n[0] = 1;
    for(int i = 1; i < 42; i++) pow3n[i] = pow3n[i-1] * 3;

    for(int ti = 1; ti <= t; ti++) {
        ll n;
        cin >> n;
        vl ans;
        for(int i = 0; i < 42; i++) {
            if(n & (1LL << i)) {
                ans.push_back(pow3n[i]);
            }
        }
        cout << ans.size() << "\n";
        for(ll a : ans) cout << a << " ";
        cout << "\n";
        //cout << "Case #" << ti << ": " ; 
    }

    return 0;
}