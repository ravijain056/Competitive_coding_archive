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
        int n, x;
        cin >> n >> x;
        vpii A(n);
        for(int i = 0; i < n; i++) {
            int a;
            cin >> a;
            A[i] = mp((a-1)/x, i);
        }
        sort(A.begin(), A.end());
        
        cout << "Case #" << ti << ": " ; 
        for(pii a : A) cout << a.second+1 << " ";
        cout << "\n";
    }

    return 0;
}