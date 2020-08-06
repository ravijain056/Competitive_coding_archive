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

        unordered_map<int, int> cnt;

        for(int i = 0; i < n; i++) {
            int w;
            cin >> w;

            if(cnt.find(w) == cnt.end()) cnt.insert(make_pair(w, 1));
            else cnt[w]++;
        }

        int maxcnt = 0;
        for(int i = 2; i <= 2 * n; i++) {
            int cnt1 = 0;
            for(int j = 1; j <= i/2; j++) {
                int k = i - j;
                if(j == k) {
                    cnt1 += cnt[j]/2;
                } else {
                    cnt1 += min(cnt[j], cnt[k]);
                }
            }
            maxcnt = max(maxcnt, cnt1);
        }
        cout << maxcnt << "\n";
    }

    return 0;
}