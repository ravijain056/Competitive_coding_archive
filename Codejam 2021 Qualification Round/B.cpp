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

int min_switch(int x, int y, string s) {
    int ans = 0;
    char prev = '?';
    for(char ch : s) {
        if(prev == '?') prev = ch;
        if(ch != prev && ch != '?') {
            prev = ch;
            if(ch == 'J') ans += x;
            else ans += y;
        }
    }
    return ans;
}

int max_switch(int x, int y, string s) {
    int ans = 0;
    char prev = '?';
    int i = 0;
    while(i < s.size()) {
        if(s[i] != '?') break;
        i++;
    }
    if(i == s.size()) {
        if(x > y) swap(x, y);
        i--;
        ans = i/2 * (x+y);
        if(i&1) ans += x;
    } else {
        i--;
        while(i >= 0) {
            if(s[i+1] == 'C') s[i] = 'J';
            else s[i] = 'C';
            i--;
        }
        prev = s[0];
        for(char ch : s) {
            if(ch == '?') 
                if(prev == 'J') ch = 'C';
                else ch = 'J';
            if(ch != prev) {
                prev = ch;
                if(ch == 'J') ans += x;
                else ans += y;
            }
        }
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
        int x, y;
        cin >> x >> y;
        string s;
        cin >> s;

        int ans = 0;

        if(x >= 0 && y >= 0) {
            ans = min_switch(x, y, s);
        } else if(x <= 0 && y <= 0) {
            ans = max_switch(x, y, s);
        } else if(x >= 0 && y <= 0) {
            if(s[0] == '?') s[0] = 'J';
            if(s[s.size()-1] == '?') s[s.size()-1] = 'C';
            if(abs(y) > x) ans = max_switch(x, y, s);
            else ans = min_switch(x, y, s);
        } else if(x <=0 && y >= 0) {
            if(s[0] == '?') s[0] = 'C';
            if(s[s.size()-1] == '?') s[s.size()-1] = 'J';
            if(abs(x) > y) ans = max_switch(x, y, s);
            else ans = min_switch(x, y, s);
        }
        
        cout << "Case #" << ti << ": " << ans << "\n"; 
    }

    return 0;
}
