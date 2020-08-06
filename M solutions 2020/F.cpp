// Incomplete

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<pair<int, int> > U, D, R, L;

    for(int i = 0; i < n; i++) {
        int x, y;
        char u;
        cin >> x >> y >> u;
        if(u == 'U') U.push_back(make_pair(x, y));
        if(u == 'D') D.push_back(make_pair(x, y));
        if(u == 'R') R.push_back(make_pair(y, x));
        if(u == 'L') L.push_back(make_pair(y, x));
    }

    int ans = INT_MAX;

    sort(U.begin(), U.end());
    sort(D.begin(), D.end());

    int ui = 0, di = 0;
    while(ui < U.size() && di < D.size()) {
        int ux = U[ui].first, dx = D[di].first;
        if(ux < dx) ui++;
        else if(ux > dx) di++;
        else {
            int uy = U[ui].second, dy = D[di].second;
            if(uy > dy) di++;
            else if(uy == dy) {
                ans = 0;
                break;
            } else {
                ans = min((dy - uy) * 5, ans);
                ui++;
            }
        }
    }

    if(ans == 0) {
        cout << ans;
        return 0;
    }

    sort(R.begin(), R.end());
    sort(L.begin(), L.end());

    int ri = 0, li = 0;
    while(ri < R.size() && li < L.size()) {
        int ry = R[ri].first, ly = L[li].first;
        if(ry < ly) ri++;
        else if(ry > ly) li++;
        else {
            int rx = R[ri].second, lx = L[li].second;
            if(rx > lx) li++;
            else if(rx == lx) {
                ans = 0;
                break;
            } else {
                ans = min((lx - rx) * 5, ans);
                ri++;
            }
        }
    }

    if(ans == 0) {
        cout << ans;
        return 0;
    }
    
    if(ans == INT_MAX) cout << "SAFE";
    else cout << ans;

    vector<pair<int, pair<int, int> > > Up, Down, Left, Right;

    for (auto u : U) Up.push_back(make_pair(u.first+u.second, u));
    for (auto d : D) Up.push_back(make_pair(d.first+d.second, d));
    for (auto l : L) Up.push_back(make_pair(l.first+l.second, l));
    for (auto r : R) Up.push_back(make_pair(r.first+r.second, r));
    
    sort(Up.begin(), Up.end());
    sort(Right.begin(), Right.end());

    int ui = 0, ri = 0;
    while(ui < Up.size() && ri < Right.size()) {
        int ut = Up[ui].first, rt = Right[ri].first;

        if(ut < rt) ui++;
        else if(ut > rt) ri++;
        else {
            int ut = Up[ui].first, rt = Right[ri].first;
            int rx = R[ri].second, lx = L[li].second;
            if(rx > lx) li++;
            else if(rx == lx) {
                ans = 0;
                break;
            } else {
                ans = min((lx - rx) * 5, ans);
                ri++;
            }
        }
    }

    return 0;
}