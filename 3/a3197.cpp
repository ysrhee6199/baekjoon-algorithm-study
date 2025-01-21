#include <bits/stdc++.h>

using namespace std;
int n,m,swanY,swanX,ay,ax,day;
string s;
char map_[1501][1501];
queue<pair<int,int>> waterQ,swanQ,swan_tempQ,water_tempQ;
int visited[1501][1501], visited_swan[1501][1501];
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
void Qclear(queue<pair<int, int>> &q){
   queue<pair<int, int>> empty;
   swap(q,empty);
}  

void water_melting() {
    while(waterQ.size()) {
        tie(ay,ax) = waterQ.front();
        waterQ.pop();
        for(int i = 0; i<4; i++) {
            int ny = ay + dy[i];
            int nx = ax + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
            visited[ny][nx] = 1;
            water_tempQ.push({ny,nx});
            map_[ny][nx] = '.';
        }
    }
}

bool move_swan() {
    while(swanQ.size()) {
        tie(ay,ax) = swanQ.front();
        swanQ.pop();
        for(int i = 0; i<4; i++) {
            int ny = ay + dy[i];
            int nx = ax + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited_swan[ny][nx]) continue;
            visited_swan[ny][nx] = 1;
            if(map_[ny][nx] == '.') swanQ.push({ny,nx});
            else if(map_[ny][nx] == 'X') swan_tempQ.push({ny,nx});
            else if(map_[ny][nx] == 'L') return true;
        }
    }

    return false;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i = 0;i < n; i++) {
        cin >> s;
        for(int j = 0; j<s.size();j++) {
            map_[i][j] = s[j];
            if(map_[i][j] == 'L') {swanY = i; swanX = j;}
            if(map_[i][j] == '.' || map_[i][j] == 'L') {visited[i][j]=1; waterQ.push({i,j});} 
        }
    }
    swanQ.push({swanY,swanX});
    visited_swan[swanY][swanX] = 1;
    while(true) {
        if(move_swan()) break;
        water_melting();
        waterQ = water_tempQ;
        swanQ = swan_tempQ;
        Qclear(water_tempQ);
        Qclear(swan_tempQ);
        day++;
    }

    cout << day << "\n";
    return 0;

}