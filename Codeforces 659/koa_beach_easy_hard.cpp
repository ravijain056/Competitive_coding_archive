#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;

    while(t--) {
        int n, k, l;
        cin >> n >> k >> l;

        int maxd = k, mini = 0;
        bool pos = true;
        for(int i = 0; i < n; i++) {
            int d;
            cin >> d;
            int maxk = l - d;
            if(maxk >= k) maxd = k;
            else maxd = min(maxd-1, maxk);
            if(maxd >= 0) mini = 0;
            else ++mini;
            if(mini > maxk) pos = false;
        }
        if(pos) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}