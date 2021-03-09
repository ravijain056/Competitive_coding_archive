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

        bool win1 = true, control = false;

        for(int i = 0; i < n; i++) {
            int a;
            cin >> a;
            
            if(!control && a == 1 && i != n-1) {
                win1 ^= 1;
            } else {
                control = true;
            }
        }

        if(win1) cout << "First\n";
        else cout << "Second\n";

    }

    return 0;
}