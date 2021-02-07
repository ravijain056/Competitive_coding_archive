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

    ll k;
    cin >> k;

    int n = 0, m = 0, M = 0;

    for(int i = 1; i < 61; i++) {
        if((1LL << i) & k) {
            n = 2 * i;
            if(M != 0) m += 2;
            M = 4 * i;
        }
    }
    if(k & 1) m++;
    m += M;
    n +=2 ;

    cout << n << " " << m << "\n";

    if(k & 1) cout << 1 << " " << n << "\n";

    if(n > 2) {
        cout << 1 << " " << 2 << "\n";
        cout << 1 << " " << 3 << "\n";
    }
    int i = 3;
    while(i + 2 < n) {
        cout << i-1 << " " << i+1 << "\n";
        cout << i-1 << " " << i+2 << "\n";
        cout << i << " " << i+1 << "\n";
        cout << i << " " << i+2 << "\n";
        i+=2;
    }

    for(int i = 1; i < 61; i++) {
        if((1LL << i) & k) {
            cout << 2*i << " " << n << "\n";
            cout << 2*i+1 << " " << n << "\n";
        }
    }

 
    return 0;
}