#include <bits/stdc++.h>

using namespace std;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int n,m,k;
int x_1,y_1,x_2,y_2;
int map_[104][104];
int visited[104][104];
int ax,ay;
vector<int> ret_;
int tmp;

void dfs(int y, int x) {
    tmp++;
    visited[y][x] = 1;
    for(int i = 0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if(visited[ny][nx] || map_[ny][nx] == 1) continue;
        dfs(ny,nx);
    }
}

int main() {

    cout.tie(NULL);
    cin.tie(NULL);
    cin >> n >> m >> k;
    
    for(int i =0; i<k; i++){
        cin >> x_1 >> y_1 >> x_2 >> y_2;
        for(int j = y_1; j < y_2; j++) {
            for(int s = x_1; s < x_2; s++) {
                map_[j][s] = 1;
            }
        }
    }
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m;j++) {
            if(visited[i][j] || map_[i][j] == 1 ) continue;
            tmp = 0;
            dfs(i,j);
            ret_.push_back(tmp);
        }
    }

    sort(ret_.begin(),ret_.end());
    cout << ret_.size() << "\n";
    for(auto i : ret_) {
        cout << i << " ";
    }
}