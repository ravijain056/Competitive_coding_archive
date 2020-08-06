#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<long, int> pli;

#define mp make_pair


int main() {
    freopen("running_on_fumes_chapter_1_input.txt", "r", stdin);
    freopen("output_1.txt", "w", stdout);

    int T;
    cin >> T;

    for(int ti = 1; ti <= T; ti++) {
        int n, m;
        cin >> n >> m;

        vi C(n);
        vector<ll> minC(n);
        for(int i = 0; i < n; i++) cin >> C[i];

        priority_queue<pli, vector<pli>, greater<pli> > heap;

        heap.push(mp(0, 0));
        for(int i = 1; i < m; i++) {
            if(C[i] != 0) heap.push(mp(C[i], i));
            minC[i] = 0;
        }

        bool pos = true;

        for(int i = m; i < n; i++) {
            pli cur;
            while(true) {
                if(heap.empty()) {
                    pos = false;
                    break;
                }
                cur = heap.top();
                if(cur.second < i-m) heap.pop();
                else break;
            }
            if(!pos) break;
            minC[i] = cur.first;
            if(C[i] != 0) heap.push(mp(minC[i] + C[i], i));
        }

        ll ans = -1;
        if(pos) ans = minC[n-1];
        cout << "Case #" << ti << ": " << ans << "\n"; 
    }

    return 0;
}