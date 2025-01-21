#include <bits/stdc++.h>
using namespace std;

int n,m;
int y_1,x1,y2,x2;
int map_[305][305];
int visited[305][305];

int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
int ay,ax;
int turn;
bool ok = false;

int main() {
    //fill(&visited[0][0],&visited[0][0]+305*305,-1);
    cin >> n >> m;

    cin >> y_1 >> x1 >> y2 >> x2;

    y_1 -= 1;
    x1 -= 1;
    y2 -= 1;
    x2 -= 1;

    for(int i = 0; i<n;i++)  {
        string s;
        cin >> s;
        for(int j = 0; j< s.size(); j++) {
            if(s[j] == '1') map_[i][j] = 1;
            else if(s[j] == '0') map_[i][j] = 0;
            else if(s[j] == '#') map_[i][j] = 1;
            else if(s[j] == '*') map_[i][j] = 8;
        }
    }

    queue<pair<int,int>> q;
    q.push({y_1,x1});
    while(q.size()) {
        fill(&visited[0][0],&visited[0][0]+305*305,0);
        visited[y_1][x1] = 1;
        turn++;
        while(q.size()) {
            tie(ay,ax) = q.front();
            q.pop();
            for(int i = 0; i<4; i++) {
                int ny = ay + dy[i];
                int nx = ax + dx[i];

                if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                if(visited[ny][nx]) continue;
                if(map_[ny][nx] == 1) {
                    map_[ny][nx] = 0;
                    visited[ny][nx] = turn;
                    if(ny == y2 && nx == x2) ok=true;
                }
                else if(map_[ny][nx] == 0 ) {
                    visited[ny][nx] = turn;
                    q.push({ny,nx});
                }
            }
            if(ok) break;
        }
        if(ok) break;
        else q.push({y_1,x1});
        
        
    }

    cout << turn << '\n';




}