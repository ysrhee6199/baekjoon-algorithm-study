#include <bits/stdc++.h>

using namespace std;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int n,m,c,k;
int x_,y_;
int map_[54][54];
int visited[54][54];
int cnt;

void dfs(int y, int x) {
    visited[y][x] = 1;
    for(int i =0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if(visited[ny][nx]) continue;
        if(map_[ny][nx] == 0) continue;
        dfs(ny,nx); 
    }
}

int main() {
    cin >> c;
    for(int i =0; i<c ;i++) {
         cin >> m >> n >> k;
        for(int j = 0;j<k;j++) {
            cin >> x_ >> y_;
            map_[y_][x_] = 1;
        }

        for(int k=0; k<n; k++) {
            for(int l = 0; l <m ;l++) {
                if(visited[k][l] || map_[k][l] == 0) continue;
                cnt++;
                dfs(k,l);
            }
        }
        cout << cnt << "\n";
        memset(map_,0,54*54*sizeof(int));
        memset(visited,0,54*54*sizeof(int));
        cnt = 0;
    }
}