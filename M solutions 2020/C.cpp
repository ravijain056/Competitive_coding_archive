#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, k;
    
    cin >> n >> k;
    
    vi arr(n);

    for(int i = 0; i < n; i++) cin >> arr[i];
    
    for(int i = k; i < n; i++) {
        if(arr[i] > arr[i-k]) cout << "Yes\n";
        else cout << "No\n";
    }
    
    return 0;
}