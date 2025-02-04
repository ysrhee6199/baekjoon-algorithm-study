#include "bits/stdc++.h"
using namespace std;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int r,c;
char map_[21][21];
int ret = 0;


void go(int y, int x,int value,int cnt)
{
    ret = max(ret,cnt);
    for(int i =0;i<4;i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
        int next_ = 1 << (int)(map_[ny][nx] - 'A');
        if(value & next_) continue;
        go(ny,nx,value | next_ , cnt+1);   
    }
    return;
}

int main()
{
    cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);

    cin >> r >> c;

    for(int i = 0; i< r; i++)
    {
        for(int j = 0; j<c; j++)
        {
            cin >> map_[i][j];
        }
    }

    go(0,0,1 << (int)(map_[0][0] - 'A'),1);

    cout << ret << "\n";

    return 0;
}