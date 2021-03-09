#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        unordered_set<int> A;

        for(int i = 0; i < n; i++) {
            int a;
            cin >> a;
            A.insert(a);
        }

        int bmatch = -1;

        for(int j = 0; j < m; j++) {
            int b;
            cin >> b;
            if(bmatch == -1 && A.find(b) != A.end()) {
                bmatch = b;
            }
        }

        if(bmatch == -1) cout << "NO\n";
        else cout << "YES\n1 " <<  bmatch << "\n";
    }

    return 0;
}