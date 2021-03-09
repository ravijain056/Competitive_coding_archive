#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define mp make_pair
#define pb push_back

const int mod = 1e9+7;

int main() {

    #ifdef LOCAL_DEV
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for(int ti = 1; ti <= t; ti++) {
        int n, x, y;
        cin >> n >> x >> y;

        vvi idx(n+2);
        vi out(n);

        for(int i = 0; i < n; i++) {
            int a;
            cin >> a;
            idx[a].pb(i);
        }
        
        priority_queue<pii> heap;

        int no_occur;
        for(int i = 1; i <= n+1; i++) {
            if(idx[i].size() == 0) no_occur = i;
            else heap.push(mp(idx[i].size(), i));
        }
        
        for(int i = 0; i < x; i++) {
            pii cur = heap.top();
            heap.pop();

            out[idx[cur.second].back()] = cur.second;
            idx[cur.second].pop_back();

            cur.first--;
            if(cur.first > 0) heap.push(cur);
        }

        if(!heap.empty() && (2 * heap.top().first) - (n-x) > (n - y)) {
            cout << "NO\n";
            continue;
        }
        
        vpii circ;
        
        int ncn = n-y;

        while(!heap.empty()) {
            pii cur = heap.top();
            heap.pop();
            
            while(cur.first--) {
                circ.pb(mp(cur.second, idx[cur.second].back()));
                idx[cur.second].pop_back();
            }
        }

        for(int i = 0; i < circ.size(); i++) {
            int y = (i + (circ.size()) / 2) % circ.size();
            if(circ[i].first == circ[y].first && ncn > 0) {
                out[circ[y].second] = no_occur;   
                ncn--;
            } else out[circ[y].second] = circ[i].first;
        }

        for(int i = 0; i < circ.size(); i++) {
            if(ncn == 0) break;
            if(out[circ[i].second] != no_occur) {
                out[circ[i].second] = no_occur;
                ncn--;
            }
        }

        cout << "YES\n";
        for(int o : out) cout << o << " ";
        cout << "\n";
    }

    return 0;
}
