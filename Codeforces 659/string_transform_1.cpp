#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;



int main() {
    #ifdef LOCAL_DEV
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        bool pos = true;

        vector<set<int> > conv(20);

        for(int i = 0; i < n; i++) {
            if(a[i] > b[i]) {
                pos = false;
                break;
            } else if(a[i] < b[i])
                conv[a[i] - 'a'].insert(b[i] - 'a');
        }
        
        if(pos) {
            int count = 0;

            for(int i = 0; i < 19; i++) {
                if(conv[i].empty()) continue;
                count++;
                auto it = conv[i].begin();
                int c = *it++;
                while(it != conv[i].end()) {
                    conv[c].insert(*it);
                    it++;
                }
            }

            cout << count << "\n";
        } else cout << "-1\n";
    }

    return 0;
}