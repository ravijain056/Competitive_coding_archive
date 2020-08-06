#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int x;
    cin >> x;

    int cls;
    if(x < 600) cls = 8;
    else if(x < 800) cls = 7;
    else if(x < 1000) cls = 6;
    else if(x < 1200) cls = 5;
    else if(x < 1400) cls = 4;
    else if(x < 1600) cls = 3;
    else if(x < 1800) cls = 2;
    else cls = 1;

    cout << cls;

    return 0;
}