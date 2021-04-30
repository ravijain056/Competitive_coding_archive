#include<bits/stdc++.h>

using namespace std;

typedef long long ls;
typedef __int128 ll;
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

const ll mod = 360 * 12 * (ll)1e10;
const ll modinv11 = 1570909090909091;
const ll modinv719 = 2319221140472879;

ll check(ll a, ll b, ll c) {
    ll tb = (b - 12 * a + 12 * mod) % mod;
    tb = (tb * modinv11)%mod;
    ll tc = (c - 720 * a + 720 * mod) % mod;
    tc = (tc * modinv719)%mod;
    if(tb != tc) return -1;
    return (a + tc) % mod;
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
        ls a, b, c;
        cin >> a >> b >> c;

        ls ans = -1;
        if(ans == -1) ans = check(a, b, c);
        if(ans == -1) ans = check(a, c, b);
        
        if(ans == -1) ans = check(b, a, c);
        if(ans == -1) ans = check(b, c, a);

        if(ans == -1) ans = check(c, b, a);
        if(ans == -1) ans = check(c, a, b);

        ls n = (ans % (ll)1e9);
        ans -= n;
        ans /= (ll)1e9;
        ls s = ans % 60;
        ans -= s;
        ans /= 60;
        ls m = ans % 60;
        ans -= m;
        ans /= 60;
        
        cout << "Case #" << ti << ": " << ans << " " << m << " " << s << " " << n << "\n"; 
    }

    return 0;
}
