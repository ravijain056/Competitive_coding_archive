#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;

    while(t--) {
        ll l, r, m;
        cin >> l >> r >> m;
        ll a, b, c;
        a = l;
        while(true) {
            ll diff = m % a;
            b = r;
            c = r - diff;
            if(c >= l && c <= r && m != (b-c)) break;
            diff = a - diff;
            c = r;
            b = c - diff;
            if(b >= l && b <= r && m != (b-c)) break;
            a++;
        }
        cout << a << " " << b << " " << c << "\n";
    }

    return 0;
}