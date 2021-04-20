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
vector<vector<__int128> > coeff(120, vector<__int128>(60, -1));

struct frac{
    __int128 z = 0, w = 1;
};  

frac reduce(frac a) {
    __int128 gcd = __gcd(a.z, a.w);
    a.z /= gcd;
    a.w /= gcd;
    return a;
}

string flip(string ans) {
    for(int i = 0; i < ans.size(); i++) {
        if(ans[i] == 'F') ans[i] = 'T';
        else ans[i] = 'F';
    }
    return ans;
}

char flipbit(char in) {
    return (in == 'F') ? 'T' : 'F';
}



__int128 bin(int k, int n) {
    if(k > n/2) k = n-k;
    if (k == 0) return 1;
    if (k == 1) return n;

    if(coeff[n][k] == -1) 
        coeff[n][k] = bin(k-1, n-1) + bin(k, n-1);
    return coeff[n][k];

}

__int128 get_num_ways(vi scores, vi qs) {
    __int128 num_ways = 0;
    for(int t0 = 0; t0 <= qs[0]; t0++) {
        int c0 = scores[0] - t0;
        int c1 = scores[1] - t0 - qs[2] - qs[3];
        int c2 = scores[2] - t0 - qs[1] - qs[3];

        int t1 = c0 + c1;
        int t2 = c0 + c2; 
        int t3 = -(c1 + c2);
        
        if(t1 < 0 || t2 < 0 || t3 < 0 || t1&1 || t2&1 || t3&1
            || t1 > qs[1]*2 || t2 > qs[2]*2 || t3 > qs[3]*2) continue;
        t1 >>= 1;
        t2 >>= 1;
        t3 >>= 1;

        num_ways += bin(t0, qs[0]) * bin(t1, qs[1]) * bin(t2, qs[2]) * bin(t3, qs[3]);
    }
    return num_ways;
}

string itos(__int128 n) {
    if(n == 0) return "0";
    string s;
    while(n > 0) {
        s.pb('0' + n % 10);
        n /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}

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
        int n, q;
        cin >> n >> q;
        vector<string> answers(n);
        vi scores(n);
        for(int i = 0; i < n; i++) {
            cin >> answers[i] >> scores[i];
            if(scores[i] < (q+1)/2) {
                answers[i] = flip(answers[i]);
                scores[i] = q - scores[i];
            }
        }

        if(n == 3) {
            if((scores[2] == scores[1] && answers[2] == answers[1]) ||
                (scores[2] == scores[0] && answers[2] == answers[0])) n--;
            else if(scores[1] == scores[0] && answers[1] == answers[0]) {
                swap(scores[1], scores[2]);
                swap(answers[1], answers[2]);
                n--;
            }
        }

        if (n == 3) {
            vb comp(q, false);
            vi type(q);

            for(int i = 0; i < q; i++) {
                if(answers[0][i] == 'F') {
                    comp[i] = true;
                    for(int j = 0; j < n; j++) 
                        answers[j][i] = flipbit(answers[j][i]);
                }
                if(answers[1][i] == 'T' && answers[2][i] == 'T')  type[i] = 0;
                else if(answers[1][i] == 'T' && answers[2][i] == 'F') type[i] = 1;
                else if(answers[1][i] == 'F' && answers[2][i] == 'T') type[i] = 2;
                else if(answers[1][i] == 'F' && answers[2][i] == 'F') type[i] = 3;
            }
            
            vi qs(4, 0);
            for(int i = 0; i < q; i++) qs[type[i]]++;
            
            
            __int128 total_ways = get_num_ways(scores, qs);
            
            vector<char> ans(4);

            frac expected_score;
            expected_score.w = total_ways;

            for(int i = 0; i < 4; i++) {
                qs[i]--;
                scores[0]--;
                if(i < 2) scores[1]--;
                if((i&1) == 0) scores[2]--;

                __int128 num_ways_T = get_num_ways(scores, qs);
                __int128 num_ways_F = total_ways - num_ways_T;

                qs[i]++;
                scores[0]++;
                if(i < 2) scores[1]++;
                if((i&1) == 0) scores[2]++;

                if(num_ways_T > num_ways_F) {
                    ans[i] = 'T';
                    expected_score.z += qs[i] * num_ways_T;
                } else {
                    ans[i] = 'F';
                    expected_score.z += qs[i] * num_ways_F;
                }
            }

            expected_score = reduce(expected_score);

            cout << "Case #" << ti << ": " ;
            for(int i = 0; i < q; i++) cout << (comp[i] ? flipbit(ans[type[i]]) : ans[type[i]]);
            cout << " " << itos(expected_score.z) << "/" << itos(expected_score.w) << "\n";
            
        } else {
            if(n == 2) { 
                if(scores[1] > scores[0]) {
                    swap(scores[1], scores[0]);
                    swap(answers[1], answers[0]);
                }
            }
            cout << "Case #" << ti << ": " << answers[0] << " " << scores[0] << "/1\n"; 
        }
    }

    return 0;
}
