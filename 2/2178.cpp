#include <bits/stdc++.h>

using namespace std;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int map_[104][104];
int n,m;
int fy,fx;
int ay,ax;
int visited[104][104];

void bfs(int y,int x) {
    queue<pair<int,int>> q;
    visited[y][x] = 1;
    q.push({y,x});
    while(q.size()) {
        tie(ay,ax) = q.front();
        q.pop();
        for(int i =0;i<4;i++){
            int ny = ay + dy[i];
            int nx = ax + dx[i];
            if(ny < 0 || nx < 0 || ny >=n || nx >= m) continue;
            if(visited[ny][nx]) continue;
            if(map_[ny][nx] == 0) continue;
            visited[ny][nx] = visited[ay][ax] + 1;
            q.push({ny,nx});
        }
    }
}


int main() {
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  string s;
  for(int i = 0; i <n ; i++) {
    cin >> s;
    for(int j = 0; j<m; j++) {
        map_[i][j] = s[j]  == '0' ? 0  : 1;
    }
  }

  fy = n-1;
  fx = m-1;
  bfs(0,0);

  cout << visited[fy][fx] << "\n";

  return 0;
}