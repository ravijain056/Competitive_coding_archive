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
        ll n, s;
        cin >> n >> s;
        ll tn = n;
        vl N;
        while(n) {
            N.pb(n%10);
            n /= 10;
        }
        N.pb(0);
        int sum = 0;
        for(int i = N.size()-1; i >= 0; i--) {
            sum += N[i];
            if(sum > s) {
                sum -= N[i];
                for(int j = i; j >= 0; j--) N[j] = 0;
                if(N[i+1] == 9) {
                    int j = i+1;
                    while(N[j] == 9) {
                        N[j] = 0;
                        j++;
                    }
                    N[j]++;
                    break;
                } 
                if(sum == s) {
                    int j = i+1;
                    while(N[j] == 0) j++;
                    N[j++] = 0;
                    while(N[j] == 9) N[j++] = 0;
                    N[j]++;
                    break;
                }
                N[i+1]++;
                break;
            }
        }

        reverse(N.begin(), N.end());
        for(ll x : N) n = n*10 + x;
        cout << n - tn << "\n";
        
        //cout << "Case #" << ti << ": " ; 
    }

    return 0;
}