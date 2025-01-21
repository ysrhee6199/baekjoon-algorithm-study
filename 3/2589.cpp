#include <bits/stdc++.h>

using namespace std;
int map_[54][54];
int visited[54][54];
int n,m;
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
int ay,ax;
int ret_ = -99;

void bfs(int y, int x) {
    visited[y][x] = 1;
    queue<pair<int,int>> q;
    q.push({y,x});
    while(q.size()) {
        tie(ay,ax) = q.front();
        q.pop();
        for(int i = 0; i<4;i++) {
            int ny = ay + dy[i];
            int nx = ax + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if(visited[ny][nx] || map_[ny][nx] == 0) continue;
            visited[ny][nx] = visited[ay][ax] + 1;
            q.push({ny,nx});
            ret_ = max(visited[ny][nx],ret_);
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i =0;i <n;i++) {
        string s;
        cin >> s;
        for(int j=0;j<s.size();j++) {
            if(s[j]=='W') map_[i][j] = 0;
            else if(s[j] == 'L') map_[i][j] = 1;
        }
    }
    int result = -1;
    for(int i = 0; i<n;i++) {
        for(int j = 0; j<m;j++) {
            if(map_[i][j] == 0) continue;
            bfs(i,j);
            result = max(result,ret_);
            memset(visited,0,54*54*sizeof(int));
        }
    }

    cout << result-1 << "\n";


    return 0;

}