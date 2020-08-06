#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
    freopen("alchemy_input.txt", "r", stdin);
    freopen("output_1.txt", "w", stdout);

    int T;
    cin >> T;

    for(int ti = 1; ti <= T; ti++) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> cnt(2, 0);
        for(int i = 0; i < n; i++) {
            cnt[s[i] - 'A']++;
        }

        char ans = (cnt[0] == n/2 || cnt[1] == n/2) ? 'Y' : 'N';
        cout << "Case #" << ti << ": " << ans << "\n"; 
    }

    return 0;
}