#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vi a(n);
        vector<string> s(n+1);
        for(int i = 0; i < n; i++) cin >> a[i];
        char cur = 'a';
        for(int i = 0; i < a[0]; i++) {
            s[0].push_back(cur++);
            if(cur == 'y') cur = 'a';
        }
        a.push_back(0);
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < a[i-1]; j++) {
                s[i].push_back(s[i-1][j]);
            }
            if(s[i-1].length() > a[i-1] && cur == s[i-1][a[i-1]]) cur++;
            for(int j = 0; j < a[i] - a[i-1]; j++) {
                s[i].push_back(cur++);
                if(cur == 'y') cur = 'a';
            }            
        }
        bool d = true;
        for(int i = 0; i <= n; i++) {
            if(s[i].length() == 0) {
                if(d) s[i].push_back('y');
                else s[i].push_back('z');
                d ^= true;
            }
            cout << s[i] << "\n";
        }

    }

    return 0;
}