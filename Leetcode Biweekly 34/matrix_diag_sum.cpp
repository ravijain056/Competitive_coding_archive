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

int solve(vvi& mat) {
    int n = mat.size();
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += mat[i][i];
        if(n-1-i != i) sum+= mat[i][n-1-i];
    }
    return sum;
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
        vvi mat(n, vi(n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) cin >> mat[i][j];
        
        cout << solve(mat) << "\n";
        //cout << "Case #" << ti << ": " ; 
    }

    return 0;
}