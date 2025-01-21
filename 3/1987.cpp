#include <bits/stdc++.h>
using namespace std;

int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
int n,m;
char map_[21][21];
int visited[21][21];
string s,a;
int cnt = 1;

void dfs(int y, int x) {
    for(int i = 0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny  < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) {
            int size = a.size();
            cnt = max(cnt,size);
            continue;
        }
        if(a.find(map_[ny][nx]) != string::npos) {
            int size = a.size();
            cnt = max(cnt,size);
            continue;
        }
        visited[ny][nx] = 1;
        a += map_[ny][nx];
        dfs(ny,nx);
        visited[ny][nx] = 0;
        a.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i<n; i++) {
        cin >> s;
        for(int j = 0; j<s.size(); j++) {
            map_[i][j] = s[j];
        }
    }

    visited[0][0] = 1;
    a += map_[0][0];
    dfs(0,0);

    cout << cnt << '\n';

    return 0;
}