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

vi ans;

const int mod = 1e9+7;

bool hasSoln(int n, int k) {
    if((n & 1) == 0) return false;
    if(k == 0 && (n & (n+1)) != 0) return false;
    if(k == 1 && (n & (n+1)) == 0) return false;
    if(n == 1 && k != 0) return false;
    if(n == 1 && k == 0) return true;
    if(k > (n - 3) / 2) return false;
    if(k == 2 && n == 9) return false;
    return true;
}

void fill(int i, int n, int k) {
    if(n == 1) return;
    if(k > 2) {
        if(k == 3 && n == 11) {
            ans[i + 1] = i;
            ans[i + 4] = i;
            fill(i+1, 3, 0);
            fill(i+4, 7, 2);
        } else {
            ans[i + 1] = i;
            ans[i + 2] = i;
            fill(i+2, n-2, k-1);
        }
    } else if(k == 2) {
        if(hasSoln(n-2, k-1)) {
            ans[i + 1] = i;
            ans[i + 2] = i;
            fill(i+2, n-2, k-1);
        } else {
            ans[i+1] = i;
            ans[i+4] = i;
            fill(i+1, 3, 0);
            fill(i+4, n-4, k-1);
        }
    } else if(k == 1) {
        int m = (int)log2(n);
        int num1 = (1 << m);
        int num2 = n + 1 - num1;
        if(num2 * 2 == num1) {
            ans[i+1] = i;
            ans[i+num2] = i;
            fill(i+1, num2 - 1, 0);
            fill(i+num2, num1 - 1, 0);
        } else {
            if(num2 * 2 < num1) {
                num1 = (1 << (m-1));
                num2 = n + 1 - num1;
            }
            ans[i + 1] = i;
            ans[i + num1] = i;
            fill(i+1,  num1 - 1, 0);
            fill(i+num1, num2 - 1, 1);
        } 
    } else { // k==0
        int hn = (n-1)/2;
        ans[i + 1] = i;
        ans[i + 1 + hn] = i;
        fill(i+1, hn, 0);
        fill(i+1+hn, hn, 0);
    }
}

int main() {

    #ifdef LOCAL_DEV
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    
    if(hasSoln(n, k)) {
        cout << "YES\n";
        ans.resize(n+1);
        ans[1] = 0;
        fill(1, n, k);
        for(int i = 1; i <=n; i++) cout << ans[i] << " ";
        cout << "\n";
    } else cout << "NO\n";

    return 0;
}
