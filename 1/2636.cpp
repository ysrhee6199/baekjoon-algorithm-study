#include "bits/stdc++.h"
using namespace std;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int visited_[101][101];
int map_[101][101];
int n ,m,count_,time_;
vector<pair<int,int>> melt_pos;

void dfs(int y, int x)
{
    visited_[y][x] = 1;

    for(int i = 0; i<4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >=n || nx < 0 || nx >= m) continue;
        if(visited_[ny][nx]) continue; 
        if(map_[ny][nx] == 1)
        {
            melt_pos.push_back({ny,nx});
            continue;
        }
        dfs(ny,nx);
    }

}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for(int i = 0; i <n;i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> map_[i][j];
            if(map_[i][j] == 1) count_++;
        }
    }

    int prev_count_ = 0;
    while(true)
    {
        fill(&visited_[0][0], &visited_[0][0]+ 101 * 101 , 0);
        prev_count_ = count_;
        time_++;

        //find_melting_pos
        dfs(0,0);

        //melting
        for(int i = 0; i < melt_pos.size(); i++)
        {
            if(map_[melt_pos[i].first][melt_pos[i].second] != 0) {
                count_--;
                map_[melt_pos[i].first][melt_pos[i].second] = 0;
            }
            else continue;
        }
        melt_pos.clear();

        
        if(count_ == 0)
        {
            cout << time_ << "\n";
            cout << prev_count_ << "\n";
            break;
        }
    }

    return 0;
}