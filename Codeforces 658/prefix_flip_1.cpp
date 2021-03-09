#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


string invflip(string a, int n) {
    string new_a = a;

    for(int i = 0; i < n; i++) {

        new_a[i] = '1' - a[n-i-1] + '0';
    }
    return new_a;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        
        string a, b;
        cin >> a >> b;

        vector<int> ops;

        for(int i = n-1; i >= 0; i--) {
            if(a[i] == b[i]) continue;
            if(b[i] == a[0]) {
                ops.push_back(1);
                a = invflip(a, 1);
            }
            ops.push_back(i+1);
            a = invflip(a, i+1);
        }

        cout << ops.size() << " ";
        for(int o : ops) cout << o << " ";
        cout << "\n";
    }

    return 0;
}