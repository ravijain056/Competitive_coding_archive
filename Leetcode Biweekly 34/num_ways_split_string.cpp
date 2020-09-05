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

int solve(string s){
    const int mod = 1e9+7;
    long long cnt1 = 0;
    long long n = s.size();
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') cnt1++;
    }
    if(cnt1 % 3 != 0) return 0;
    if(cnt1 == 0) return ((n-1) * (n-2) / 2) % mod;
    long long c1 = 0, c2 = 1, c3 = 1;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') c1++;
        else if(s[i] == '0' && c1 == cnt1/3) c2++;
        else if(s[i] == '0' && c1 == cnt1*2/3) c3++;
    }
    return (c2 * c3) % mod;
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
        string s;
        cin >> s;
        cout << solve(s) << "\n";
    }

    return 0;
}