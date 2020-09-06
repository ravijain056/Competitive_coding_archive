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

int solve(vi nums1, vi nums2) {
    map<long long, int> nums12, nums22, nums1ij, nums2ij;
    int n = nums1.size(), m = nums2.size();
    for(int i = 0; i < n; i++) {
        ll a = 1LL * nums1[i] * nums1[i];
        if(nums12.find(a) != nums12.end()) nums12[a]++;
        else nums12[a] = 1;
        for(int j = i+1; j < n; j++) {
            a = 1LL * nums1[i] * nums1[j];
            if(nums1ij.find(a) != nums1ij.end()) nums1ij[a]++;
            else nums1ij[a] = 1;
        }
    }
    for(int i = 0; i < m; i++) {
        ll a = 1LL * nums2[i] * nums2[i];
        if(nums22.find(a) != nums22.end()) nums22[a]++;
        else nums22[a] = 1;
        for(int j = i+1; j < m; j++) {
            a = 1LL * nums2[i] * nums2[j];
            if(nums2ij.find(a) != nums2ij.end()) nums2ij[a]++;
            else nums2ij[a] = 1;
        }
    }
    
    int ans = 0;
    for(auto it = nums12.begin(); it!=nums12.end(); it++) {
        ll a = it->first;
        auto it2 = nums2ij.find(a);
        if(it2 != nums2ij.end()) ans += it->second * it2->second;
    }
    for(auto it = nums22.begin(); it!=nums22.end(); it++) {
        ll a = it->first;
        auto it2 = nums1ij.find(a);
        if(it2 != nums1ij.end()) ans += it->second * it2->second;
    }
    return ans;
}

int main() {

    #ifdef LOCAL_DEV
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for(int ti = 1; ti <= t; ti++) {
        int n, m;
        cin >> n >> m;
        vi nums1(n), nums2(m);
        for(int i = 0; i < n; i++) cin >> nums1[i];
        for(int i = 1; i < m; i++) cin >> nums2[i];
        cout << solve(nums1, nums2) << "\n";
    }

    return 0;
}