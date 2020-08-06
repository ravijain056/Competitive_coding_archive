#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> id;
        vector<int> zeroes, ones;
        int cnti = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == '0') {
                if(ones.empty()) {
                    zeroes.push_back(++cnti);
                    id.push_back(zeroes.back());
                } else {
                    zeroes.push_back(ones.back());
                    id.push_back(zeroes.back());
                    ones.pop_back();
                }
            } else {
                if(zeroes.empty()) {
                    ones.push_back(++cnti);
                    id.push_back(ones.back());
                } else{
                    ones.push_back(zeroes.back());
                    id.push_back(ones.back());
                    zeroes.pop_back();
                }
            }
        }

        cout << cnti << "\n";
        for(int i : id) {
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}