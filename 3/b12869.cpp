#include <bits/stdc++.h>

using namespace std;
int n;
int a[3];
int visited[64][64][64];
int ret;

int a_[6][3] = {
    {9,3,1},
    {9,1,3},
    {3,9,1},
    {3,1,9},
    {1,9,3},
    {1,3,9}
};

struct A {
    int a,b,c;
};
queue<A> q;
void bfs(int a, int b, int c) {
    visited[a][b][c]  =  1;
    q.push({a,b,c});
    while(q.size()) {
        
        int a = q.front().a;
        int b = q.front().b;
        int c = q.front().c;
        q.pop();
        if(visited[0][0][0]) {
            ret = visited[0][0][0]  - 1;
        }
        for(int i = 0; i <6; i++) {
            int na = max(0, a - a_[i][0]);
            int nb = max(0, b - a_[i][1]);
            int nc = max(0, c - a_[i][2]);
            if(visited[na][nb][nc]) continue;
            visited[na][nb][nc] = visited[a][b][c] + 1;
            q.push({na,nb,nc});
        }
    }
}

int main() {
    cin >> n;
    for(int i = 0; i<n; i++) {
        cin >> a[i];
    }

    bfs(a[0],a[1],a[2]);
    cout << ret << "\n";

    return 0;

}