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

int n, q, l;
vi d;
vi IL, IR;
vi par, lc, rc, cnt;
vvi pardp;

void dfs(int i) {
    cnt[i] = 1;
    if(rc[i] != -1) {
        dfs(rc[i]);
        cnt[i] += cnt[rc[i]];
    }
    if(lc[i] != -1) {
        dfs(lc[i]);
        cnt[i] += cnt[lc[i]];
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for(int ti=1; ti <= T; ti++) {
        cin >> n >> q;

        d.resize(n-1);
        for(int i = 0; i < n-1; i++) {
            cin >> d[i];
        }

        IL.resize(n-1);
        IR.resize(n-1);
        IL[0] = -1;
        vpii ld;
        ld.push_back(mp(d[0], 0));
        for(int i = 1; i < n-1; i++) {
            while(!ld.empty() && ld.back().first < d[i]) ld.pop_back();
            if(ld.empty()) IL[i] = -1;
            else IL[i] = ld.back().second;
            ld.push_back(mp(d[i], i));
        }

        IR[n-2] = -1;
        vpii rd;
        rd.push_back(mp(d[n-2], n-2));
        for(int i = n-3; i >= 0; i--) {
            while(!rd.empty() && rd.back().first < d[i]) rd.pop_back();
            if(rd.empty()) IR[i] = -1;
            else IR[i] = rd.back().second;
            rd.push_back(mp(d[i], i));
        }

        int root;
        par.resize(n-1);
        lc.assign(n-1, -1);
        rc.assign(n-1, -1);
        for(int i = 0; i < n-1; i++) {
            if(IR[i] == -1 && IL[i] == -1) {
                par[i] = -1;
                root = i;
            } else if(IR[i] == -1) {
                par[i] = IL[i];
                rc[IL[i]] = i;
            } else if(IL[i] == -1) {
                par[i] = IR[i];
                lc[IR[i]] = i;
            } else if(d[IL[i]] < d[IR[i]]) {
                par[i] = IL[i];
                rc[IL[i]] = i;
            } else {
                par[i] = IR[i];
                lc[IR[i]] = i;
            }
        }

        l = ceil(log2(n-1)) + 2;
        pardp.assign(n-1, vi(l));

        for(int i = 0; i < n-1; i++) pardp[i][0] = par[i];

        for(int j = 1; j < l; j++) {
            for(int i = 0; i < n-1; i++) {
                if(pardp[i][j-1] == -1) pardp[i][j] = -1;
                else pardp[i][j] = pardp[pardp[i][j-1]][j-1];
            }
        }

        cnt.resize(n);
        dfs(root);

        cout << "Case #" << ti << ": ";
        while(q--) {
            int s, k;
            cin >> s >> k;
            k--;
            int x;
            if(s == 1) {
                x = s-1;
                if(cnt[x] >= k) {
                    cout << s+k << " ";
                    continue;
                }
            } else if(s == n) {
                x = s-2;
                if(cnt[x] >= k) {
                    cout << s-k << " ";
                    continue;
                }
            } else if(d[s-1] < d[s-2]) { //R
                x = s-1;
                if(cnt[x] >= k) {
                    cout << s+k << " ";
                    continue;
                } 
            } else {
                x = s-2;
                if(cnt[x] >= k) {
                    cout << s-k << " ";
                    continue;
                }
            }
            int y;
            while(true) {
                int j = 0;
                while(j < l && pardp[x][j] != -1 && cnt[pardp[x][j]] < k) j++;
                if(j == 0) {
                    y = pardp[x][j];
                    break;
                } else {
                    x = pardp[x][j-1];
                }
            }
            if(y < x) {
                cout << y + 2 - (k - cnt[rc[y]]) << " ";
            } else {
                cout << y + 1 + k - cnt[lc[y]] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}