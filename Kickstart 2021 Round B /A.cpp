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
        string s;
        cin >> s;
        
        cout << "Case #" << ti << ": 1 " ; 

        int cur = 1;
        for(int i = 1; i < n; i++) {
            if(s[i-1] < s[i]) cur++;
            else cur = 1;

            cout <<  cur << " ";
        }
        cout << "\n";
    }

    return 0;
}
