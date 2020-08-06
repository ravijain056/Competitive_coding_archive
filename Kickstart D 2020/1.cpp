#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for(int ti=1; ti <= T; ti++) {
        int n;
        cin >> n;

        vector<int> v(n);

        for(int i=0; i < n; i++) cin >> v[i];

        int maxV = -1, ans = 0;
        for(int i=0; i < n; i++) {
            if(v[i] > maxV) {
                maxV = v[i];
                if(i != n-1) {
                    if(v[i] > v[i+1]) ans++;
                } else {
                    ans++;
                }
            }
        }
        
        cout << "Case #" << ti << ": " << ans << "\n";
    }

    return 0;
}