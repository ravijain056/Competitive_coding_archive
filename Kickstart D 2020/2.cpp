#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for(int ti=1; ti <= T; ti++) {
        int k;
        cin >> k;

        vector<int> keys(k);

        for(int i=0; i < k; i++) cin >> keys[i];
        
        int cur = 0, count = 0, ans = 0;
        for(int i = 1; i < k; i++) {
            if(keys[i] > keys[i-1]) {
                if(cur == -1) {
                    count = 1;
                    cur = 1;
                } else {
                    count++;
                    cur = 1;
                    if(count == 4) {
                        ans++;
                        count = 0;
                        cur = 0;
                    }
                }
            } else if(keys[i] < keys[i-1]) {
                if(cur == 1) {
                    count = 1;
                    cur = -1;
                } else {
                    count++;
                    cur = -1;
                    if(count == 4) {
                        ans++;
                        count = 0;
                        cur = 0;
                    }
                }
            }
        }
        
        cout << "Case #" << ti << ": " << ans << "\n";
    }

    return 0;
}