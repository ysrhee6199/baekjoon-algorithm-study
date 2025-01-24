#include "bits/stdc++.h"
using namespace std;
int n,m;
vector<int> v[10004];
int visited[10004];
int dp[10004];
int mx;

int dfs(int pos)
{
    int ret= 1;
    visited[pos] = 1;
    for(int go_there : v[pos])
    {
        if(visited[go_there]) continue;
        ret += dfs(go_there);
    }
    return ret;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i =0; i<m;i++)
    {
        int a,b;
        cin >> a >> b;
        v[b].push_back(a);
    }

    for(int i =1; i<=n; i++)
    {
        fill(&visited[0] , &visited[0]+10004, 0);
        dp[i] = dfs(i);
        mx = max(dp[i],mx);
    }

    for(int i =1; i<=n; i++)
    {
        if(dp[i] == mx)
        {
            cout << i << " ";
        }
    }

}