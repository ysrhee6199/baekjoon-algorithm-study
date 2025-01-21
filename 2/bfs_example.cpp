#include <bits/stdc++.h>

using namespace std;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int map_[104][104];
int n,m;
int ay,ax;
int sy,sx; // 시작위치
int fy,fx; //끝위치
int visited[104][104];

void bfs(int y, int x) {
    visited[y][x] = 1;
    queue<pair<int,int>> q;
    q.push({y,x});
    while(q.size()) {
        tie(ay,ax) = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int ny = ay + dy[i];
            int nx = ax + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if(visited[ny][nx]) continue;
            visited[ny][nx] = visited[ay][ax] + 1;
            q.push({ny,nx});
        }
    }
}

int main() {
    cin >> n >> m;
    cin >> sy >> sx;
    cin >> fy >> fx;

    for (int i =0; i < n; i++) {
        for(int j = 0; j<m;j++) {
            cin >> map_[i][j]; 
        }
    }

    bfs(sy,sx);

    cout << visited[fy][fx] << "\n";
}