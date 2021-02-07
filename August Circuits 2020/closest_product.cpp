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

int n;
vl A, B, snapB;
ll mn;
ll s;

void get(vl C, int i, int j, ll reqdiff) {
    if(abs(reqdiff) < mn) {
        mn = abs(reqdiff);
        snapB = C;
    }
    if(i >= j) return;
    if(reqdiff <= 0) return;
    get(C, i+1, j, reqdiff);
    get(C, i, j-1, reqdiff);
    
    ll diff = (A[j] - A[i]) * (C[j] - C[i]);
    swap(C[i], C[j]);
    get(C, i+1, j-1, reqdiff - diff);
}

void getAll(int l, int r, ll ts) {
    if(l == r) {
        ll curs = 0;
        for(int i = r - 9; i <= r; i++) curs += A[i] * B[i];
        if(abs(curs - ts) < mn) {
            mn = abs(curs - ts);
            snapB = B;
        }
    } else {
        for(int i = l; i <= r; i++) {
            swap(B[l], B[i]);
            getAll(l+1, r, ts);
            swap(B[l], B[i]);
            while(B[i+1] == B[i]) {
                i++;
                if(i == n-1) break;
            }
        }
    }
}

int main() {

    #ifdef LOCAL_DEV
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin >> s;

    A.resize(n);
    B.resize(n);
    for(int i = 0; i < n; i++) cin >> A[i];
    for(int i = 0; i < n; i++) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    ll curs = 0;
    for(int i = 0; i < n; i++) curs += A[i] * B[i];

    mn = abs(curs - s);
    snapB = B;

    if(curs <= s) ;
    else if(n < 30) {
        getAll(0, n-1, s);
    } else if(n < 100) {
        int k = 25;
        while(k--) {
            for(int i = rand() % 10; i + 9 < n; i+= 10) {
                curs = 0;
                for(int j = 0; j < n; j++) {
                    if(j >= i && j <= i+9) continue;
                    curs += A[j] * B[j];
                }
                if(curs > s) {
                    sort(B.begin() + i, B.begin() + i + 10, greater<ll>());
                    snapB = B;
                } else {
                    getAll(i, i+9, s - curs);
                    B = snapB;
                }
            }
        }
        
    }else if(n < 190) {
        int k = 15e7;
        while(k--) {
            if(k % 100 == 0) {
                if(abs(curs - s) < mn) {
                    mn = abs(curs - s);
                    snapB = B;
                }
                ll tempB = B[0];
                for(int i = 0; i < n-1; i++) B[i] = B[i+1];
                B[n-1] = tempB;
                curs = 0;
                for(int i = 0; i < n; i++) curs += A[i] * B[i];
            } else {
                int i = rand() % n;
                int j = rand() % n;
                ll diff = (A[j] - A[i]) * (B[j] - B[i]);
                ll temps = curs - diff;
                if(abs(temps - s) < abs(curs - s)) {
                    swap(B[i], B[j]);
                    curs = temps;
                }
            }
        }
        
    } else {
        int k = 15e7;
        //srand(time(NULL));
        while(k--){
            if(k % max(1000, n) == 0) {
                if(abs(curs - s) < mn) {
                    mn = abs(curs - s);
                    snapB = B;
                }
                int i = rand() % n;
                int j = rand() % n;
                ll diff = (A[j] - A[i]) * (B[j] - B[i]);
                curs -= diff;
                swap(B[i], B[j]);
                if(abs(curs - s) < mn) {
                    mn = abs(curs - s);
                    snapB = B;
                }
            } else {
                int i = rand() % n;
                int j = rand() % n;
                ll diff = (A[j] - A[i]) * (B[j] - B[i]);
                ll temps = curs - diff;
                if(abs(temps - s) < abs(curs - s)) {
                    swap(B[i], B[j]);
                    curs = temps;
                }
            }
        }
    } 
    
    for(int i = 0; i < n; i++) cout << A[i] << " ";
    cout << "\n";
    for(int i = 0; i < n; i++) cout << snapB[i] << " ";
    cout << "\n";
 
    return 0;
}

