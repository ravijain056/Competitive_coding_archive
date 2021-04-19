#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
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
        int n;
        cin >> n;
        vi A(n), diffA(n-1);
        
        for(int i = 0; i < n; i++) cin >> A[i];
        
        int ans = 1;
        
        for(int i = 0; i < n-1; ) {
            int diff = A[i+1] - A[i];
            int j = i+2;
            int curL = 2;
            while(j < n) {
                if(A[j] - A[j-1] != diff) break;
                else curL++;
                j++;
            }
            
            if(j == n && i != 0) curL++;
            else if(j != n) {
                curL++;
                int k = j+1;
                if(A[k] - A[k-2] == 2 * diff) {
                    k++;
                    curL++;
                    while(k < n) {
                        if(A[k] - A[k-1] != diff) break;
                        else curL++;
                        k++;
                    }
                } 
            } 
            i = j-1;
            ans = max(ans, curL);

        }

        reverse(A.begin(), A.end());

        for(int i = 0; i < n-1; ) {
            int diff = A[i+1] - A[i];
            int j = i+2;
            int curL = 2;
            while(j < n) {
                if(A[j] - A[j-1] != diff) break;
                else curL++;
                j++;
            }
            
            if(j == n && i != 0) curL++;
            else if(j != n) {
                curL++;
                int k = j+1;
                if(A[k] - A[k-2] == 2 * diff) {
                    k++;
                    curL++;
                    while(k < n) {
                        if(A[k] - A[k-1] != diff) break;
                        else curL++;
                        k++;
                    }
                } 
            } 
            i = j-1;
            ans = max(ans, curL);

        }

        cout << "Case #" << ti << ": " << ans << "\n"; 
    }

    return 0;
}
