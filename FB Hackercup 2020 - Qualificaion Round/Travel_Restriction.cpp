#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
    freopen("travel_restrictions_input.txt", "r", stdin);
    freopen("output_1.txt", "w", stdout);

    int T;
    cin >> T;

    
    for(int ti = 1; ti <= T; ti++) {
        int n;
        cin >> n;        
        string I, O;
        cin >> I >> O;

        vector<bool> cL(n-1), cR(n-1);

        for(int i = 1; i < n; i++) {
            cR[i-1] = (O[i-1] == 'Y' && I[i] == 'Y');
            cL[i-1] = (O[i] == 'Y' && I[i-1] == 'Y');
        }

        cout << "Case #" << ti << ":\n";

        vector<vector<char> > ans(n, vector<char>(n, 'N'));
        for(int i = 0; i < n; i++) {
            ans[i][i] = 'Y';
            for(int j = i+1; j < n; j++) {
                if(cR[j-1]) ans[i][j] = 'Y';
                else break;   
            }
            for(int j = i-1; j >= 0; j--) {
                if(cL[j]) ans[i][j] = 'Y';
                else break;
            }
        }

        for(vector<char> vo : ans) {
            for(char o : vo) {
                cout << o;
            }
            cout << "\n";
        }
    }

    return 0;
}