#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    
    string s;
    cin >> s;

    int n = s.length();

    vector<int> char_occur(26, 0);
    vector<vector<int> > occur_idx(26,vector<int>());

    for(int i = 0; i < n; i++) {
        char_occur[s[i] - 'a']++;
        occur_idx[s[i] - 'a'].push_back(i);
    }

    int max_occur = 0;

    for(int i = 0; i < 26; i++) {
        max_occur = max(max_occur, char_occur[i]);
    }

    int maxj = 0, maxji;


    for(int i = 0; i < 26; i++) {
        if(char_occur[i] == max_occur) {
            vector<bool> vis(26, false);
            vis[i] = true;
            int j = 1;
            while(true) {
                int cur_idx = occur_idx[i][0] + j;
                if(cur_idx == n) break;

                char cur = s[cur_idx];
                if(vis[cur-'a']) break;
                
                bool match = true;
                for(int k : occur_idx[i]) {
                    if(s[cur_idx] != cur) {
                        match = false;
                        break;
                    }
                }
                if(!match) break;
                j++;
            }
            if(j > maxj) {
                maxj = j;
                maxji = occur_idx[i][0];
            } else if(j == maxj) {
                maxji = min(maxji, occur_idx[i][0]);
            }
        }
    }
    
    for(int i = 0; i < maxj; i++) {
        cout << s[i+maxji];
    }

    return 0;
}