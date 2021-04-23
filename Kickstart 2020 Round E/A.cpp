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

    for(int ti = 1; ti <= t; ti++) {
        int n;
        cin >> n;
        vi A(n);
        for(int i = 0; i < n; i++) cin >> A[i];

        int mx = 2, cur = 2, curdiff = A[1] - A[0];
        for(int i = 2; i < n; i++) {
            if(A[i] - A[i-1] == curdiff) {
                cur++;
                if(cur > mx) mx = cur;
            } else {
                curdiff = A[i] - A[i-1];
                cur = 2;
            }
        }
        
        cout << "Case #" << ti << ": " << mx << "\n"; 
    }

    return 0;
}