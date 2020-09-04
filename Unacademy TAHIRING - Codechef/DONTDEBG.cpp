#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mod 1000000007
#define MAX_N 10011
 
vector < int > graph[MAX_N], rev_graph[MAX_N];
stack < int > s;

bool visited[MAX_N] = {0};
bool visited2[MAX_N] = {0};
 
int indegree[MAX_N] = {0};
int represent_node[MAX_N] = {0};
 
void dfs(int node) {
    visited[node] = true;
 
    for (int x: graph[node])
        if (!visited[x])
            dfs(x);
 
    s.push(node);
}
 
void dfs2(int node, int representative) {
    visited2[node] = true;
    represent_node[node] = representative;
 
    for (int x: rev_graph[node])
        if (!visited2[x])
            dfs2(x, representative);
}
 
int main() {
    #ifdef LOCAL_DEV
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    FIO;
    int t, n, m, k, i, j, ans;
    cin >> t;
    while (t--> 0) {
        cin >> n >> m;

        for(i = 1; i <= n; i++) {
            graph[i].clear();
            rev_graph[i].clear();
            visited[i] = 0;
            visited2[i] = 0;
            indegree[i] = 0;
        }

        while (m--> 0) {
            cin >> j >> k;
            graph[j].push_back(k);
            rev_graph[k].push_back(j);
        }
 
        s = stack<int>();     
        
        for (i = 1; i <= n; i++)
            if (!visited[i])
                dfs(i);
 
        while (s.size() > 0) {
            j = s.top();

            if (!visited2[j])
                dfs2(j, j);
            s.pop();
        }
 
        for (i = 1; i <= n; i++)
            for (int x: graph[i])
                if (represent_node[i] != represent_node[x])
                    indegree[represent_node[x]]++;

        ans = 0;
        for (i = 1; i <= n; i++)
            if (represent_node[i] == i)
                if(indegree[i] == 0)
                    ans++;
        cout << ans << "\n";
    }
    return 0;
} 