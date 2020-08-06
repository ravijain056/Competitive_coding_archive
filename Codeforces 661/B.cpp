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

        vector<int> C(n), O(n);

        int minC = INT_MAX, minO = INT_MAX;
        for(int i = 0; i < n; i++) {
            cin >> C[i];
            minC = min(minC, C[i]);
        }
        for(int i = 0; i < n; i++) {
            cin >> O[i];
            minO = min(minO, O[i]);
        }

        ll cnt = 0;
        for(int i = 0; i < n; i++) {
            cnt += max(C[i] - minC, O[i] - minO);
        }
        cout << cnt << "\n";
    }

    return 0;
}