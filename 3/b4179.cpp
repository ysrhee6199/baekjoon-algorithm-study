#include <bits/stdc++.h>

using namespace std;

int n,m;
int map_[1004][1004];
int fire_visited[1004][1004];
int visited[1004][1004];
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
pair<int,int> J_p;
queue<pair<int,int>> F_p_;
int ay,ax;
int ret = 987654321;

int main() {
    cin >> n >> m;
    fill(&fire_visited[0][0],&fire_visited[0][0]+1004*1004,987654321);
    for (int i = 0; i<n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j<s.size(); j++) {
            if(s[j] == '#') map_[i][j] = 0;
            else if(s[j] == '.') map_[i][j] = 1;
            else if(s[j] == 'J') {
                J_p = {i,j};
                visited[i][j] = 1;
            }
            else if(s[j] == 'F') {
                F_p_.push({i,j});
                map_[i][j] = 3;
                fire_visited[i][j] = 1;
            }
        }
    }


    while(F_p_.size()) {
        tie(ay,ax) = F_p_.front();
        F_p_.pop();
        for(int i = 0; i<4; i++) {
            int ny = ay + dy[i];
            int nx = ax + dx[i];
            if(ny < 0 || nx < 0 || ny >=n || nx >= m) continue;
            if(map_[ny][nx] == 0 || fire_visited[ny][nx] != 987654321) continue;
            fire_visited[ny][nx] = fire_visited[ay][ax] + 1;
            F_p_.push({ny,nx}); 
        }
    }


    queue<pair<int,int>> q;
    q.push(J_p);
    while(q.size()) {
        tie(ay,ax) = q.front();
        q.pop();
        for(int i = 0; i<4; i++) {
            int ny = ay + dy[i];
            int nx = ax + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) {
                ret = min(ret,visited[ay][ax]);
                break;
            }
            if(visited[ny][nx] || map_[ny][nx] == 0 || map_[ny][nx] == 3) continue;
            int tmp = visited[ay][ax] + 1;
            if(tmp >= fire_visited[ny][nx]) continue;
            visited[ny][nx] = tmp;
            q.push({ny,nx});
        }
    }

    if(ret == 987654321) cout << "IMPOSSIBLE" << '\n';
    else cout << ret << '\n';

    return 0;




}