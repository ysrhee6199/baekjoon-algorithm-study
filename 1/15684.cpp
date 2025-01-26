#include "bits/stdc++.h"
using namespace std;
int n,m,h; // 세로선 가로선 가로선을 놓을수있는 위치의 개수
int a,b;
int visited[34][34]; // visited[1층][1] == 1층에서 1번사다리에서 오른쪽으로 가는 사다리가 있음
// 2번 사다리 관점에서 visited[1층][2-1] == 1층에서 2번사다리에서 왼쪽으로 가는 사다리가 있음
const int INF = 987654321;
int ret = 987654321;

bool check()
{
    for(int i = 1; i<=n;i++)
    {
        int start = i; // 시작 사다리 번호
        for(int j=1;j<=h;j++)
        {
            if(visited[j][start]) start++; // 오른쪽 사다리로 이동동
            else if(visited[j][start-1]) start--; // 왼쪽 사다리로 이동동
        }
        if(start != i) return false;
    }
    return true;
}

void go (int here, int cnt)
{
    //백트래킹
    if( cnt > 3 || cnt >= ret) return;
    if(check())
    {
        ret = min(ret,cnt);
        return;
    }

    //탐색색
    for(int i = here; i<=h; i++)
    {
        for(int j = 1; j<=n; j++)
        {
            if(visited[i][j] || visited[i][j-1] || visited[i][j+1]) continue; // 이미 연결되어있음
            visited[i][j] = 1;
            go(i,cnt+1);
            visited[i][j] = 0;
        }
    }
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> h;

    for(int i = 0; i<m; i++)
    {
        cin >> a >> b; // a층에 b번 세로선과 b+1 세로선이 연결되어있음음
        visited[a][b] = 1;
    }

    go(1,0);


    if(ret == INF) cout << -1 << "\n";
    else cout << ret << "\n";
    return 0;
}