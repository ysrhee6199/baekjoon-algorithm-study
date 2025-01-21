#include <bits/stdc++.h>
using namespace std;
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
int dp[54][54];
int map_[54][54];
int visited[54][54];
int n,m;
string s;

int dfs(int y, int x) {
    if(y < 0 || x < 0 || y >= n || x >= m) return 0;
    if(map_[y][x] == 'H') return 0;
    if(visited[y][x]) {
        cout << -1 << "\n";
        exit(0);
    }

    int &ret = dp[y][x];
    if(ret) return ret;
    
    visited[y][x] = 1;
    int num = (int)map_[y][x] - '0';

    for(int i = 0; i<4; i++) {
        int ny = y + dy[i] * num;
        int nx = x + dx[i] * num;
        ret = max(ret, dfs(ny,nx) + 1);
    }
    visited[y][x] = 0;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i< n; i++) {
        cin >> s;
        for(int j =0; j<m;j++) {
            map_[i][j] = s[j];
        }
    }

    cout << dfs(0,0) << "\n";

    return 0;
}