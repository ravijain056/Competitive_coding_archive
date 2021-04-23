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

    int t;
    cin >> t;
    vi out1;

    for(int ti = 1; ti <= t; ti++) {
        cout << "Case #" << ti << ": " ; 
        int n, a, b, c;
        cin >> n >> a >> b >> c;
        if(n == 1) {
            cout << "1\n";
        } else if(n + c < a + b || (a == 1 && b == 1)) {
            cout << "IMPOSSIBLE\n";
        } else {
            out1.assign(n, 2);
            if(n == 2) {
                if(a == 2) out1[0] = 1;
                if(b == 2) out1[1] = 1;
            } else if(a == c && b == c) {
                for(int i = 0; i < c-1; i++) out1[i] = 3;
                out1[n-1] = 3;
            } else if(b == c) {
                for(int i = a - c; i < n - b; i++) out1[i] = 1;
                for(int i = n - b; i < n; i++) out1[i] = 3;
            } else {
                for(int i = a-c; i < a; i++) out1[i] = 3;
                for(int i = a; i < n - b + c; i++) out1[i] = 1;
            }

            for(int o : out1)
                cout << o << " ";
            cout << "\n";
        }
        
    }

    return 0;
}