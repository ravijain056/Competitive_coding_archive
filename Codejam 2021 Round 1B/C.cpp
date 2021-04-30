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

int n, b;
int optimdig = 2;

class vihash {
public:
  
    size_t operator()(const vi& p) const {
        size_t ret = 0, mul = 1;
        for(int i = 0; i < n; i++) {
            ret += p[i] * mul;
            mul *= (b+1);
        }
        return ret;
    }
};

unordered_map<vi, double, vihash> dp;

vi getplaces(vi status) {
    vi places;
    int skip = b;
    for(int i = 0; i < n; i++) {
        if(status[i] < b - optimdig) {
            places.pb(i);
            break;
        } else if(status[i] < skip) {
            places.pb(i);
            skip = status[i];
        }
    }
    return places;
}

double get_exp(vi status) {
    if(dp.find(status) != dp.end()) return dp[status];
    if(status[n-1] == b) return 0;

    vi places = getplaces(status);
    dp[status] = 0;
    for(int i = 0; i < 10; i++) {
        double cur = 0;
        for(int p : places) {
            status[p]++;
            if(status[p] <= b - optimdig) {
                cur = max(cur, get_exp(status));
            } else {
                int mul = pow(10, optimdig - 1 - b + status[p]);
                cur = max(cur, i*mul + get_exp(status));
            }                
            status[p]--;
        }
        dp[status] += cur;
    }
    dp[status] /= 10;

    return dp[status];
}

int main() {

    int t;
    ll p;
    cin >> t >> n >> b >> p;
    ll sum = 0;
    //vl sums;
    //vi lstatus;
    //vvi blocks(n);
    for(int ti = 1; ti <= t; ti++) {
        int exc = n * b;
        vi status(n, 0);
        while(exc--) {
            int d;
            cin >> d;
            vi places = getplaces(status);
            
            double cur = -1, temp;
            int ans = places[0];

            if(places.size() == 1) places.clear();
            
            for(int p : places) {
                status[p]++;

                if(status[p] <= b - optimdig) {
                    temp = get_exp(status);
                } else {
                    int mul = pow(10, optimdig - 1 - b + status[p]);
                    temp = d*mul + get_exp(status);
                }                
                
                if(cur < temp) {
                    cur = temp;
                    ans = p;
                }
                status[p]--;
            }

            //blocks[ans].pb(d);
            //sum += pow(10, status[ans]) * d;
            status[ans]++;
            cout << ans + 1 << "\n" << flush;
        }
        //sums.pb(sum);
        //lstatus = status;
    }
    int res;
    cin >> res;
/*
    freopen("output.txt", "w", stdout);
    cout << p << " " << n << " " << b << "\n";
    cout << sum << "\n";
    lstatus.assign(n, 0);
    cout << get_exp(lstatus) << "\n";
    cout << dp.size() << "\n";
    for(int i = 0; i < n; i++) {
        cout << blocks[i][b-1] << " " << blocks[i][b-2] << "\n";
    }
 //   for(ll s : sums) cout << s << " ";
//    cout << "\n";
    //for(int l : lstatus) cout << l << " ";*/
    return 0;
}
