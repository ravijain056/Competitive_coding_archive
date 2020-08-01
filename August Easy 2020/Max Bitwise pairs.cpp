#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        int n, q;
        cin >> n;
        vector<int> A(n);
        for(int i = 0; i < n; i++) cin >> A[i];

        cin >> q;

        vector<int> Fmax(1<<17, -1);
        for(int i = 1; i <= n; i++) Fmax[i] = A[i-1];

        for(int i = 0; i < 17; i++) {
            for(int mask = 0; mask < (1 << 17); mask++) {
                if(mask & (1 << i)) {
                    Fmax[mask] = max(Fmax[mask], Fmax[(1<<i)^mask]);
                }
            }
        }

        int mask = (1 << 17) -1;

        while(q--){
            int i;
            cin >> i;
            int ans = Fmax[mask ^ i];

            if(ans == -1) cout << "-1\n";
            else cout << A[i-1] + ans << "\n";
        }

    }

    return 0;
}