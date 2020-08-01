#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> specials;

int n;


int main() {
    
    cin >> n;

    if(n < 7) {
        cout << 0;
        return 0;
    }

    specials.push_back(4);
    specials.push_back(7);

    int start = 0, end = 2;
    while(start != end) {
        for(int i = start; i < end; i++) {
            ll cur = specials[i] * 10 + 4;
            if(cur <= n) specials.push_back(cur);
            cur = specials[i] * 10 + 7;
            if(cur <= n) specials.push_back(cur);
        }
        start = end;
        end = specials.size();
    }

    ll cnt = 0;
    for(int i = 0; i < specials.size(); i++) {
        for(int j = i+1; j < specials.size(); j++) {
            if(__gcd(specials[j], specials[i]) == 1) cnt++;
        }
    }    

    cout << cnt;
    return 0;
}