#include "bits/stdc++.h"
using namespace std;
const int INF = 987654321;
int ret = INF;
int n; //구역의 개수
int p[11]; // 구역별 인구수
vector<int> adj[11]; //인접리스트
int visited[11]; //방문리스트트
int comp[11];

pair<int,int> dfs(int here, int value)
{
    visited[here] = 1;
    pair<int,int> ret = {1,p[here]};
    for(int there : adj[here])
    {
        if(comp[there] != value) continue;
        if(visited[there]) continue;
        pair<int,int> tmp_  = dfs(there,value);
        ret.first += tmp_.first;
        ret.second += tmp_.second;
    }
    return ret;
}

int main()
{
    cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i = 1; i<=n; i++)
    {
        cin >> p[i];
    }

    for(int i = 1; i<=n;i++)
    {
        int tmp = 0;
        cin >> tmp;

        for(int j =0; j<tmp; j++)
        {
            int node_ = 0;
            cin >> node_;
            adj[i].push_back(node_);
            adj[node_].push_back(i);
        }
    }

    for(int i = 1; i < (1 << n) -1; i++ ) // 2개의 컴포넌트로 나누지 않는 경우의 수 ex) 0000,1111 제외외
    {
        //초기화화
        fill(comp,comp+11,0); // 노드들을 2개의 컴포넌트로 분리하는 배열
        fill(visited,visited+11,0);

        int idx1 = -1;
        int idx2 = -1;
        // i의 비트 중 0 과 1을 기반으로 컴포넌트 두개로 나눔 그중 하나는 dfs 시작 index
        for(int j = 0; j<n; j++)
        {
            if(i & ( 1 << j))
            {
                comp[j+1] = 1;
                idx1 = j+1;
            }
            else 
            {
                idx2 = j+1;
            }
        }

        pair<int,int> comp1 = dfs(idx1,1);
        pair<int,int> comp2 = dfs(idx2,0);

        if(comp1.first + comp2.first == n) // dfs 방문 노드의 합이 총 노드의 갯수와 맞으면
        {
            ret = min(ret, abs(comp1.second - comp2.second));
        }

    }

    if(ret != INF)
    {
        cout << ret << "\n";
    }
    else 
    {
        cout << -1 << "\n";
    }



    return 0;
}