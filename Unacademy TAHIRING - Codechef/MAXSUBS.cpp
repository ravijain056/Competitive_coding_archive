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

    int n;
    cin >> n;

    vi A(n);
    for(int i = 0; i < n; i++) cin >> A[i];


    int id = 0;
  
    for (int i = 31; i >= 0; i--) 
    { 
        int maxInd = id; 
        int maxEle = INT_MIN; 
        for (int j = id; j < n; j++) 
        { 
            if ( (A[j] & (1 << i)) != 0  
                     && A[j] > maxEle ) 
                maxEle = A[j], maxInd = j; 
        } 
  
        if (maxEle == INT_MIN) 
        continue; 
  
        swap(A[id], A[maxInd]); 
  
        maxInd = id; 
  
        for (int j=0; j<n; j++) 
        { 
            if (j != maxInd && 
               (A[j] & (1 << i)) != 0) 
                A[j] = A[j] ^ A[maxInd]; 
        } 
  
        id++; 
    } 
  
    int ans = 0; 
    for (int i = 0; i < n; i++) 
        ans ^= A[i]; 

    cout << ans;

    return 0;
}