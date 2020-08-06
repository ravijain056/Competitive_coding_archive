#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a, b, c, k;
    cin >> a >> b >> c >> k;

    int cnt = 0;
    while(b <= a) {
        b*=2;
        cnt++;
    }
    while(c <= b) {
        c *= 2;
        cnt++;
    }

    if(cnt <= k) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}