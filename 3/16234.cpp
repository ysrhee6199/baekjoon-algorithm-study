#include <bits/stdc++.h>

using namespace std;
int n,l,r;
int map_[54][54];
int visited[54][54];
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
int ay,ax;
int ty,tx;
int num_move,sum_;
int check_;
bool tmp;

void bfs(int y,int x){
    num_move = 0;
    sum_ = 0;

    visited[y][x] = 1;
    queue<pair<int,int>> q;
    queue<pair<int,int>> mem_;
    q.push({y,x});
    mem_.push({y,x});
    while(q.size()) {
        tie(ay,ax) = q.front();
        q.pop();
        num_move++;
        sum_ += map_[ay][ax];
        for(int i = 0; i<4; i++) {
            int ny = ay + dy[i];
            int nx = ax + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if(visited[ny][nx]) continue;
            int a = abs(map_[ay][ax] - map_[ny][nx]);
            if(a < l || a > r) continue;
            visited[ny][nx] = visited[ay][ax] +1;
            q.push({ny,nx});
            mem_.push({ny,nx});
        }
    }


    if(num_move > 1) {
        tmp = true;
        int b = sum_ / num_move;
        while(mem_.size()) {
            tie(ty,tx) = mem_.front();
            mem_.pop();
            map_[ty][tx] = b;
        }
    }



}


int main() {
    cin >> n >> l >> r;
    for(int i = 0; i <n;i++) {
        for(int j = 0; j<n; j++) {
            cin >> map_[i][j];
        }
    }
    check_ = 0;
    while(true) {
        tmp = false;
        for(int i = 0; i<n;i++) {
            for(int j =0; j<n;j++) {
                if(visited[i][j]) continue;
                bfs(i,j);
            }
        }      
        if(!tmp) break;
        memset(visited,0,54*54*sizeof(int));
        check_++;
    }

    cout << check_ << '\n';

    return 0;

}