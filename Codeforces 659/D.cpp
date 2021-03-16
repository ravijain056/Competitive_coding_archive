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

int getMSB(int a) {
    a |= a >> 1;
    a |= a >> 2;
    a |= a >> 4;
    a |= a >> 8;
    a |= a >> 16;
    return (a + 1) >> 1;
}


int main() {

    #ifdef LOCAL_DEV
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for(int ti = 1; ti <= t; ti++) {
        int n;
        cin >> n;

        vi A(n);
        int xorA = 0;
        
        for(int i = 0; i < n; i++) {
            cin >> A[i];
            xorA ^= A[i];
        }
        
        int msb = getMSB(xorA), x = 0, y = 0;
        for(int i = 0; i < n; i++) {
            if(msb & A[i]) x++;
            else y++;
        }

        if(msb == 0) cout << "DRAW\n";
        else if(x % 4 == 3 && y % 2 == 0) cout << "LOSE\n";
        else cout << "WIN\n";
    }

    return 0;
}
