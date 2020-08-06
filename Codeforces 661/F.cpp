#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define mp make_pair

int sz;
vvi dp;
vi nums;
unordered_map<int, int> ids;
unordered_map<int, unordered_set<int>> seg;

int getdp(int l, int r) {
    if(l >= r) return 0;
    if(dp[l][r] != -1) return dp[l][r];

    dp[l][r] = getdp(l+1, r);
    bool addseg = false;
    for(int numr : seg[nums[l]]) {
        int k = ids[numr];
        if(k == r) addseg = true;
        else if(k < r) {
            dp[l][r] = max(dp[l][r], getdp(l, k) + getdp(k+1, r));
        }
    }
    if(addseg) dp[l][r]++;

    return dp[l][r];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        nums.clear();
        seg.clear();
        ids.clear();
        int extra = 0;

        for(int i = 0; i < n; i++) {
            int l, r;
            cin >> l >> r;
            if(l == r) {
                extra++;
                continue;
            }
            nums.push_back(l);
            nums.push_back(r);
            seg[l].insert(r);
        }
        
        sort(nums.begin(), nums.end());
        sz = unique(nums.begin(), nums.end()) - nums.begin();
        nums.resize(sz);

        for(int i = 0; i < sz; i++) {
            ids.insert(mp(nums[i], i));
        }
        
        dp.assign(sz, vi(sz, -1));

        cout << getdp(0, sz-1) + extra << "\n";
    }

    return 0;
}