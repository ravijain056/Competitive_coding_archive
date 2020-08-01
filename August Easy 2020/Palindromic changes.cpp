#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    
    string s;
    cin >> s;

    int n;
    cin >> n;

    vector<vector<ll> > cost(26, vector<ll>(26, INT_MAX));

    for(int i = 0; i < n; i++) {
        char a, b;
        int c;
        cin >> a >> b >> c;
        cost[a-'a'][b-'a'] = c;
        cost[b-'a'][a-'a'] = c;
    }


    for(int i = 0; i < 26; i++) cost[i][i] = 0;

    bool update = true;
    while(update) {
        update = false;
        for(int i = 0; i < 26; i++) {
            for(int j = i+1; j < 26; j++) {
                for(int k = 0; k < 26; k++) {
                    if(i == k || k == j) continue;
                    ll curcost = cost[i][k] + cost[j][k];
                    if(curcost < cost[i][j]) {
                        cost[i][j] = curcost;
                        cost[j][i] = curcost;
                        update = true;
                    }
                }
            }
        }
    }
    int j = s.length()-1;
    int i = 0;
    ll totcost = 0;
    while(i < j) {
        totcost += cost[s[i]-'a'][s[j] - 'a'];
        i++;
        j--;
    }

    cout << totcost;
    return 0;
}