#include <bits/stdc++.h>

using namespace std;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int visited[104][104];
int map_[104][104];
int n;
int cnt;
int max_rain;
int max_ret;

void dfs(int y, int x,int r) {
    visited[y][x] = 1;
    for(int i =0; i<4;i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0|| ny >= n || ny >= n) continue;
        if(visited[ny][nx]) continue;
        if(map_[ny][nx] <= r) continue;
        dfs(ny,nx,r);

    }
}

int main() {
    cin >> n;

    for(int i =0;i<n;i++) {
        for(int j =0;j<n;j++){
            cin >> map_[i][j];
            if(map_[i][j] > max_rain) max_rain = map_[i][j];
        }
    }

    for(int i = 0; i<=max_rain; i++) {
        memset(visited,0,104*104*sizeof(int));
        
        cnt = 0;

        for(int j = 0; j<n;j++) {
            for(int k = 0; k<n; k++) {
                if(visited[j][k] == 1 ) continue;
                if(map_[j][k] <= i) continue;
                cnt++;
                dfs(j,k,i);
            }
        }

        if(cnt>max_ret) max_ret = cnt;
    }

    cout << max_ret << "\n";
}