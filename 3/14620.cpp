#include <bits/stdc++.h>
using namespace std;

int map_[11][11];
int visited[11][11];
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
int n;
int ret = 987654321;
int cnt;

void eraseflower(int y, int x) {
    visited[y][x] = 0;
    for(int i = 0; i<4; i++) {
        int ny= y + dy[i];
        int nx= x + dx[i];
        visited[ny][nx] = 0;
    }
}

bool check(int y, int x) {
    if(visited[y][x]) return false;
    for(int i = 0; i<4; i++) {
        int ny= y + dy[i];
        int nx= x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n) return false;
        if(visited[ny][nx] == 1) return false;
    }

    return true;
}

int setflower(int y,int x) {
    visited[y][x] = 1;
    int sum = map_[y][x];
    for(int i = 0; i<4; i++) {
        int ny= y + dy[i];
        int nx= x + dx[i];
        visited[ny][nx] = 1;
        sum += map_[ny][nx];
    }

    return sum;
}

void flower(int cnt, int hap) {
    if(cnt == 3) {
        ret = min(hap,ret);
        return;
    }

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            if(check(i,j)) {
                flower(cnt+1,hap+setflower(i,j));
                eraseflower(i,j);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            cin >> map_[i][j];
        }
    }


    flower(0,0);

    cout << ret << "\n";

    return 0;
}