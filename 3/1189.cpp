#include "bits/stdc++.h"
using namespace std;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int r,c,k; // r: 세로, c: 가로, k: 거리리
int map_[7][7];
int visited[7][7];
int home_y,home_x;
int ret;
// 집 오른쪽 위
// 현재 위치 왼쪽 아래

int go(int y, int x, int cnt)
{
    int ret_ = 0;
    if(cnt == k)
    {
        if(y == home_y && x == home_x)
        {
            return 1;
        }
        else return 0;
    }


    for(int i = 0; i<4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
        if(visited[ny][nx] == 1 || map_[ny][nx] == 1) continue;

        visited[ny][nx] = 1;
        ret_ += go(ny,nx,cnt+1);
        visited[ny][nx] = 0;

    }

    return ret_;



}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> r >> c >> k;

    for(int i = 0; i < r; i++)
    {
        string s;
        cin >> s;
        for(int p = 0; p<s.size(); p++)
        {
            if(s[p]=='T') map_[i][p]  = 1;
            else map_[i][p] = 0;
        }
    }

    home_y = 0;
    home_x = c-1;

    visited[r-1][0] = 1;

    cout << go(r-1,0,1) << "\n";
    return 0;
}