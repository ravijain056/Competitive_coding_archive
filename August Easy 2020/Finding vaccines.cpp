#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    
    int t;
    cin >> t;

    int n;
    cin >> n;

    vector<int> virus(4, 0), vac(4, 0);

    string s;
    cin >> s;

    for(int i=0; i < n; i++) {
        if(s[i] == 'A') virus[0]++;
        if(s[i] == 'C') virus[1]++;
        if(s[i] == 'G') virus[2]++;
        if(s[i] == 'U') virus[3]++;
    }

    int maxi = -1, maxval = -1;

    for(int ti = 1; ti <= t; ti++) {
        cin >> n;
        cin >> s;
        vac.assign(4, 0);
        for(int i=0; i < n; i++) {
            if(s[i] == 'A') vac[0]++;
            if(s[i] == 'C') vac[1]++;
            if(s[i] == 'G') vac[2]++;
            if(s[i] == 'U') vac[3]++;
        }
        int cnt = virus[1] * vac[2] + virus[2] * vac[1];

        if(cnt > maxval) {
            maxval = cnt;
            maxi = ti;
        }

    }   
    cout << maxi;
    return 0;
}