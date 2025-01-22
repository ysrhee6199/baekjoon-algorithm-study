#include "bits/stdc++.h"
using namespace std;

int map_[10][10];
int visited_[10][10];

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int n,m;
int cnt;
int ret;

vector<pair<int,int>> virus_list;
vector<pair<int,int>> wall_list;

void dfs(int y, int x)
{
    visited_[y][x] = 1;
    for(int i =0; i<4;i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny <0 || ny >= n || nx < 0 || nx >= m) continue;
        if(visited_[ny][nx] || map_[ny][nx] == 1) continue;
        dfs(ny,nx);
    }
}

int test()
{   
    fill(&visited_[0][0], &visited_[0][0] + 10 * 10, 0); 
    //virus
    for(int i = 0; i<virus_list.size(); i++)
    {
        if(visited_[virus_list[i].first][virus_list[i].second]) continue;
        else dfs(virus_list[i].first,virus_list[i].second );
    }

    //count cnt,
    cnt = 0;
    for(int y = 0; y < n; y++)
    {
        for(int x =0; x <m; x++)
        {
            if(map_[y][x] == 0)
            {
                if(visited_[y][x]) continue;
                cnt++;
            }
        }
    }
    return cnt;

}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for(int y = 0; y < n; y++)
    {
        for(int x =0; x <m; x++)
        {
            cin >> map_[y][x];
            if(map_[y][x] == 0) wall_list.push_back({y,x});
            if(map_[y][x] == 2) virus_list.push_back({y,x});
        }
    }

    //combi
    for(int i = 0; i<wall_list.size();i++)
    {
        for(int j = i+1; j<wall_list.size();j++)
        {
            for(int k = j+1; k<wall_list.size(); k++)
            {
                map_[wall_list[i].first][wall_list[i].second] = 1;
                map_[wall_list[j].first][wall_list[j].second] = 1;
                map_[wall_list[k].first][wall_list[k].second] = 1;
                ret = max(ret,test());
                map_[wall_list[i].first][wall_list[i].second] = 0;
                map_[wall_list[j].first][wall_list[j].second] = 0;
                map_[wall_list[k].first][wall_list[k].second] = 0;

            }
        }
    }
    cout << ret <<"\n";

    return 0;

}