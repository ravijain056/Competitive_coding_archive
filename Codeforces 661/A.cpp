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
        vector<int> A(n);
        for(int i=0; i < n; i++) cin >> A[i];

        if(n == 1) cout << "YES\n";
        else {
            sort(A.begin(), A.end()); 
            bool pos = true;
            for(int i = 0; i < n-1; i++) {
                if(A[i]+1 != A[i+1] && A[i] != A[i+1]) {
                    pos = false;
                    break;
                }
            }
            if(pos) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}