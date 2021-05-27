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

vector<vector<vector<double>>> dp;
vector<vector<vector<char>>> dpStep;

double getmax(int r, int p, int s, double e, double w) {
    if(dp[r][p][s] != -1) return dp[r][p][s];
    int i = r + p + s - 1;
    if(i == 0) {
        dp[r][p][s] = (e + w) / 3;
        return dp[r][p][s];
    }
    double choiceR = -1, choiceP = -1, choiceS = -1;
    if(r > 0) {
        choiceR = getmax(r-1, p, s, e, w);
        choiceR += (p * w + s * e)/i;
    }
    if(p > 0) {
        choiceP = getmax(r, p-1, s, e, w);
        choiceP += (s * w + r * e)/i;
    }
    if(s > 0) {
        choiceS = getmax(r, p, s-1, e, w);
        choiceS += (r * w + p * e)/i;
    }

    if(choiceP > choiceR && choiceP > choiceS) {
        dpStep[r][p][s] = 'P';
        dp[r][p][s] = choiceP;
    } else if(choiceR > choiceS) {
        dpStep[r][p][s] = 'R';
        dp[r][p][s] = choiceR;
    } else {
        dpStep[r][p][s] = 'S';
        dp[r][p][s] = choiceS;
    }
    return dp[r][p][s];
}

int main() {

    #ifdef LOCAL_DEV
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(6) << fixed;

    int t, x;
    cin >> t >> x;

    
    vector<double> max_X(4, 0);
    vvi maxStrat(4, vi(3));
    vi E = {0, 6, 22, 33};
    vi W = {66, 60, 44, 33};
    vector<string> ans(4);

    for(int i = 0; i < 4; i++) {
        dp.assign(61, vector<vector<double> >(61, vector<double>(61, -1)));
        dpStep.assign(61, vector<vector<char> >(61, vector<char>(61)));
        dpStep[0][0][1] = 'S';
        dpStep[1][0][0] = 'R';
        dpStep[0][1][0] = 'P';
        for(int r = 0; r <= 60; r++) {
            for(int p = 0; p + r <= 60; p++) {
                int s = 60 - p - r;
                double x;
                
                x = getmax(r, p, s, E[i], W[i]);
                if(x > max_X[i]) {
                    max_X[i] = x;
                    maxStrat[i] = {r, p, s};
                }
            }
        }

        int r = maxStrat[i][0], p = maxStrat[i][1], s = maxStrat[i][2];
        while(r + p + s > 0) {
            if(dpStep[r][p][s] == 'R') {
                ans[i] = "R" + ans[i];
                r--;
            } else if(dpStep[r][p][s] == 'P') {
                ans[i] = "P" + ans[i];
                p--;
            } else {
                ans[i] = "S" + ans[i];
                s--;
            }
        }
    }

    /*for(double x:max_X)
        cout << x << "\n"; 
    
    for(string a : ans) cout << a << "\n";
    */
    for(int ti = 1; ti <= t; ti++) {
        int w, e;
        cin >> w >> e;
        
        cout << "Case #" << ti << ": " ; 
        if(e == 0) cout << ans[0];
        else if(e == w/10) cout << ans[1];
        else if(e == w/2) cout << ans[2];
        else cout << ans[3];
        cout << "\n";
    }

    return 0;
}
