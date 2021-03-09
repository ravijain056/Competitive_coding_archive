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
        bool aflip = false;
        int a_start = 0;


        for(int i = n-1; i >= 0; i--) {
            if(!aflip) {
                if(a[i + a_start] == b[i]) continue;
                if(b[i] == a[a_start]) {
                    ops.push_back(1);
                    //a[a_start] = '1' - a[a_start] + '0';
                }
                ops.push_back(i+1);
                aflip = true;
                a_start++;
            } else {
                if(a[a_start] != b[i]) {
                    a_start++;
                    continue;
                }
                if(b[i] != a[a_start + i]) {
                    ops.push_back(1);
                    //a[a_start+i] = '1' - a[a_start+i] + '0';
                }
                ops.push_back(i+1);
                aflip = false;
            }
        }

        cout << ops.size() << " ";
        for(int o : ops) cout << o << " ";
        cout << "\n";
    }

    return 0;
}