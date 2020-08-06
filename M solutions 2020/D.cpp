#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    ll m = 1000;
    ll s = 0;

    vi price(n);
    for(int i = 0; i < n; i++) cin >> price[i];

    for(int i = 0; i < n-1; i++) {
        if(price[i+1] > price[i]) {
            s += (m / price[i]);
            m %= price[i];
        } else if(price[i+1] < price[i]) {
            m += s*price[i];
            s = 0;
        }
    }
    m += s*price[n-1];

    cout << m;

    return 0;
}