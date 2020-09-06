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

string solve(string s) {
    int n = s.length();
    if(s[0] == '?' && s[1] != 'a') s[0] = 'a';
    else if(s[0] == '?' && s[1] == 'a') s[0] = 'b';
    if(s[n-1] == '?' && s[n-2] != 'a') s[n-1] = 'a';
    else if(s[n-1] == '?' && s[n-2] == 'a') s[n-1] = 'b';
    
    for(int i = 1; i < n-1; i++) {
        if(s[i] == '?') {
            if(s[i-1] != 'a' && s[i+1] != 'a') s[i] = 'a';
            else if(s[i-1] != 'b' && s[i+1] != 'b') s[i] = 'b';
            else if(s[i-1] != 'c' && s[i+1] != 'c') s[i] = 'c';
        }
    }
    return s;
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