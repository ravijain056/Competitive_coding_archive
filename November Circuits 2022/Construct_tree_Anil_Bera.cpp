#include <bits/stdc++.h>
using namespace std;
 
#ifdef LOCAL
#include "log.h"
#else
#define trace(...) 
#endif
 
#define ll long long
#define int ll
#define all(x) (x).begin(),(x).end()
 
using pii = pair<int,int>;
 
pii a[10001];int s[10001];
void solve()
{
#ifdef LOCAL_DEV
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].first;
        assert(a[i].first<=10000 && a[i].first>=1);
        a[i].second = i+1;
    }
    sort(a,a+n);
    reverse(a,a+n);
    s[0]=a[0].first;
    for(int i=1;i<n;i++)
        s[i]=s[i-1]+a[i].first;
 
    int score = 0; int pos = -1;
    for(int L=round(n*0.1);L<=round(n*0.9);L++)
    {
        // 0,....,L-1
        int rem = n-L;
        int a1 = (rem+1)/2;
        int b1 = rem/2;
        swap(a1,b1);
 
        int SL = s[L-1];
        int M = a[0].first;
        int m = a[1].first;
        assert((L+a1+b1) == n);
        int Sa = s[L+a1-1]-s[L-1];
        int Sb = s[L+a1-1+b1]-s[L+a1-1];
        assert((Sa+Sb+SL) == s[n-1]);
 
        int tmp = a1*b1*(L+1)*SL + Sa*b1*(L+1) + Sb*a1*(L+1) + 2*Sa*(a1-1) +
                  2*Sb*(b1-1) + m*a1*(a1-1) + M*b1*(b1-1);
        if(tmp>score)
        {
            score = tmp;
            pos = L;
        }
    }
 
    int L = pos;
    swap(a[1],a[pos-1]);
    for(int i=1;i<pos;i++)
        cout<<a[i-1].second<<" "<<a[i].second<<"\n";
    int rem = n-L;
    int a1 = (rem+1)/2;
    int b1 = rem/2;
    swap(a1,b1);
 
    for(int i=pos;i<pos+a1;i++)
        cout<<a[i].second<<" "<<a[pos-1].second<<"\n";
    for(int i=pos+a1;i<n;i++)
        cout<<a[i].second<<" "<<a[0].second<<"\n";
 
}
 
 
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tt = 1;//cin>>tt;
    for(int i=1;i<=tt;i++)
    {
        //cout<<"Case #"<<i<<": ";
        solve();
    }
}
