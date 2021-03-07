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

    int n, h, m, k;
    cin >> n >> h >> m >> k;
    int m2 = m/2;
    if(m2 == k) {
        unordered_map<int, unordered_set<int>> pts;

        for(int i = 0; i < n; i++) {
            int hi, mi;
            cin >> hi >> mi;
            mi %= m2;
            pts[mi].insert(i);
        }
        
        int minpt;
        int minRem = n;
        for(auto pt : pts) {
            int cur = n - pt.second.size();
            if(cur < minRem) {
                minRem = cur;
                minpt = pt.first;
            }
        }

        cout << minRem << " " << minpt << "\n";
        if(minRem != 0) 
            for(int i = 0; i < n; i++) {
                if(pts[minpt].find(i) == pts[minpt].end()) cout << i + 1 << " ";
            }

        return 0;
    }

    vpii segs;
    unordered_set<int> min_fts;
    
    for(int i = 0; i < n; i++) {
        int hi, mi;
        cin >> hi >> mi;
        mi %= m2;
        
        int s1 = mi + 1, s2 = mi + k;
        segs.pb(mp(s1 % m2, n + i));
        if(s2 <= m2) segs.pb(mp(s2, i));
        else {
            if(s1 < m2) segs.pb(mp(0, n + i));
            segs.pb(mp(s2-m2, i));
        }
    }

    sort(segs.begin(), segs.end());

    int curp = 0;
    int minRemove = n;
    int curRemove = 0;
    int t = 0;

    for(int i = 0; i < segs.size(); i++) {
        if(segs[i].first != curp) {
            if(curRemove < minRemove) {
                minRemove = curRemove;
                t = curp;
            }
            if(segs[i].first == m2 || curRemove == 0) break;
            curp = segs[i].first;
        }
        if(segs[i].second >= n) curRemove++;
        else curRemove--;
        
        if(i == segs.size()-1) {
            if(curRemove < minRemove) {
                minRemove = curRemove;
                t = curp;
            }
        }
    }

    cout << minRemove << " " <<  t << "\n";
    for(int i = 0; i < segs.size(); i++) {
        if(segs[i].first > t) break;
        if(segs[i].second >= n) {
            min_fts.insert(segs[i].second - n);
        } else {
            min_fts.erase(segs[i].second);
        }
    }
    for(int f : min_fts) cout << f + 1 << " ";

    return 0;
}
