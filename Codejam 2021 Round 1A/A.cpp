#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
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
        int n;
        cin >> n;

        int count = 0;

        string prev = "";

        for(int i = 0; i < n; i++) {
            string cur;
            cin >> cur;
            if(prev.size() >= cur.size()) {
                int comp = 0;
                for(int  i = 0; i < cur.size(); i++) {
                    if(prev[i] < cur[i]) {
                        comp = 1;
                        break;
                    } else if(prev[i] > cur[i]) {
                        comp = -1;
                        break;
                    }
                }
                if(comp == 0) {
                    string app = "";
                    bool n9 = true;
                    for(int i = prev.size() - 1; i >= cur.size(); i--) {
                        if(n9) {
                            if(prev[i] == '9') app.append("0");
                            else {
                                char a = prev[i] + 1;
                                app = app + a;
                                n9 = false;
                            }
                        } else {
                            app = app + prev[i];
                        }
                    }
                    if(n9) {
                        comp = -1;
                    } else {
                        comp = 1;
                        reverse(app.begin(), app.end());
                        cur = cur + app;
                        count += app.size();
                    }
                }
                if(comp == 1) {
                    while(cur.size() < prev.size()) {
                        cur.append("0");
                        count++;
                    }
                } else if(comp == -1) {
                    while(cur.size() <= prev.size()) {
                        cur.append("0");
                        count++;
                    }
                } 
            }
            prev = cur;
        }        
        cout << "Case #" << ti << ": " << count << "\n"; 
    }

    return 0;
}
