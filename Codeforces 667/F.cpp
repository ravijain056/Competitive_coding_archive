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

    int n, k;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;
    vb upd(n, false);

    int xa = 0,  xb = n-1, ba = 0, ab = n-1;
    int xa_cntb = 0, xb_cnta = 0, ba_cntb = 0, ab_cnta = 0;
    if(s[0] == t[0]) xb_cnta++;
    if(s[n-1] == t[1]) xa_cntb++;
    for(int i = 1; i < n-1; i++) {
        if(s[i] == t[0]) xb_cnta++;
        if(s[i] == t[1]) xa_cntb++;
    }
    ba_cntb = xa_cntb;
    ab_cnta = xa_cntb;

    while(k--) {
        if(xa <= xb) {
            while(s[xa] == t[0] || s[xa] == t[1]) {
                xa++;
                if(s[xa] == t[1]) xa_cntb--;
            }
            while(s[xb] == t[0] || s[xb] == t[1]) {
                xb--;
                if(s[xb] == t[0]) xb_cnta--;
            }
        }
        
        while(s[ba] != t[1]) {
            if(ba >= (n+1)/2) break;
            ba++;
            if(s[ba] == t[1]) ba_cntb--;
        }
        while(s[ab] != t[0]) {
            if(ab < (n+1)/2) break;
            ab--;
            if(s[ab] == t[0]) ab_cnta--;
        }

        int updxa, updxb, updab, updba;

        updxa = xa_cntb;
        updxb = xb_cnta;
        updba = ba_cntb - ba;
        updab = ab_cnta - n + 1 + ab;
        
        if(t[0] == t[1]){
            updab = -1; updba = -1;
        }
        if(xa > xb) {
            updxa = -1; updxb = -1;
        }
        int maxupd = max(max(updxa, updxb), max(updba, updab));
        if(maxupd < 0) continue;

        if(updba == maxupd) {
            s[ba] = t[0];
            if(ba < xb) xb_cnta++;
            if(ba < ab) ab_cnta++;
            if(upd[ba]) k++;
            ba++;
            if(s[ba] == t[1]) ba_cntb--;
        } else if(updab == maxupd){
            s[ab] = t[1];
            if(ab > xa) xa_cntb++;
            if(ab > ba) ba_cntb++;
            if(upd[ab]) k++;
            ab--;
            if(s[ab] == t[0]) ab_cnta--;
        } else if(updxa == maxupd) {
            s[xa] = t[0];
            if(xa < xb) xb_cnta++;
            if(xa < ab) ab_cnta++;
            upd[xa] = true;
            xa++;
            if(s[xa] == t[1]) xa_cntb--;
        } else {
            s[xb] = t[1];
            if(xb > xa) xa_cntb++;
            if(xb > ba) ba_cntb++;
            upd[xb] = true;
            xb--;
            if(s[xb] == t[0]) xb_cnta--;
        }
    }
    if(t[0] != t[1]) {
        while(ba < (n+1)/2 || ab >= (n+1)/2) {
            break;
            while(s[ba] != t[1] || !upd[ba]) {
                if(ba >= (n+1)/2) break;
                ba++;
                if(s[ba] == t[1]) ba_cntb--;
            }
            while(s[ab] != t[0] || !upd[ab]) {
                if(ab < (n+1)/2) break;
                ab--;
                if(s[ab] == t[0]) ab_cnta--;
            }

            int updab, updba;

            updba = ba_cntb - ba;
            updab = ab_cnta - n + 1 + ab;
            int maxupd = max(updba, updab);
            if(maxupd <= 0) {
                break;
            }
            if(updba == maxupd) {
                s[ba] = t[0];
                if(ba < ab) ab_cnta++;
                ba++;
                if(s[ba] == t[1]) ba_cntb--;
            } else {
                s[ab] = t[1];
                if(ab > ba) ba_cntb++;
                ab--;
                if(s[ab] == t[0]) ab_cnta--;
            }
        }
    }

    int cntb = 0, cnta = 0;
    for(int i = 0; i < n; i++) if(s[i] == t[1]) cntb++;

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == t[1]) cntb--;
        if(s[i] == t[0]) {
            ans += cntb;
        }
    }

    cout << ans;
    return 0;
}