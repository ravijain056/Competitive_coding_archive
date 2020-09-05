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

int solve(vi& arr) {
    int n = arr.size();
    int i = 1;
    for(; i < n; i++) {
        if(arr[i] < arr[i-1]) break;
    }
    int ans = n-i;
    i--;
    if(ans == 0) return 0;
    int j = n-1;
    while(i >= 0) {
        if(arr[i] > arr[j]) i--;
        else {
            ans = min(ans, j-i-1);
            j--;
            if(arr[j] > arr[j+1]) break;
        }
    }
    if(i == -1) {
        while(arr[j] >= arr[j-1]) j--;
        ans = min(ans, j);
    }
    return ans;
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
        for(int i = 0; i < n; i++) cin >> A[i];
        cout << solve(A) << "\n";
    }

    return 0;
}