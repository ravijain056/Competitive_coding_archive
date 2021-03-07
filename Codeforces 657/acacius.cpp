#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

string substr = "abacaba";

int getcount(string str) {
    int cnt = 0;
    for(int i = 0; i <= str.size()-7; i++) {
        bool match = true;
        for(int j = 0; j < 7; j++) {
            if (str[i+j] != substr[j]) {
                match = false;
                break;
            }
        }
        if(match) cnt++;
    }
    return cnt;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int t;
    cin >> t;


    while(t--) {
        int n;
        cin >> n;
        string str;
        cin >> str;
        
        bool ans = false;
        int cnt = getcount(str);

        if(cnt >= 2) {
            cout << "No\n";
        } else {
            string ss;
            if(cnt == 0) {
                for(int i = 0; i <= n-7; i++) {
                    bool match = true;
                    for(int j = 0; j < 7; j++) {
                        if(str[i+j] != '?' && str[i+j] != substr[j]) {
                            match = false;
                            break;
                        }
                    }
                    if(match) {
                        ss = str;
                        for(int j = 0; j < 7; j++) ss[i+j] = substr[j];
                        if(getcount(ss) == 1) {
                            ans = true;
                            break;
                        }
                    }
                }
            } else {
                ans = true;
                ss = str; 
            }
            if(ans) {
                for(int i = 0; i < n; i++) {
                    if(ss[i] == '?') {
                        ss[i] = 'd';
                    }
                }
                cout << "Yes\n" << ss << "\n";
            } else {
                cout << "No\n";
            }
        }
    }

    return 0;
}