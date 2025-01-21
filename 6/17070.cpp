#include <bits/stdc++.h>
using namespace std;
int dp[25][25][3]; // 0 가로, 1  세로, 2 대각
int a[25][25];
int n,m;

bool check(int ny, int nx, int c) {
    if(c == 0 || c == 1) {
        if(ny <1 || nx < 1 || ny > n || nx > n || a[ny][nx]) return false;
        else return true;
    }
    else if(c == 2) {
        if(ny <1 || nx < 1 || ny > n || nx > n || a[ny][nx]) return false;
        if(ny - 1 < 1 || nx - 1 < 1 || ny-1 > n || nx - 1 > n || a[ny-1][nx] || a[ny][nx-1]) return false;
        return true;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> n;

    for(int i = 1; i<= n; i++) {
        for(int j = 1; j<=n; j++) {
            cin >> a[i][j];
        }
    }

    dp[1][2][0] = 1;
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=n; j++) {
            //초기위치가 가로일때
            if(check(i,j+1,0)) dp[i][j+1][0] += dp[i][j][0];
            if(check(i+1,j+1,2)) dp[i+1][j+1][2] += dp[i][j][0];
            
            //초기위치가 세로
            if(check(i+1,j,1)) dp[i+1][j][1] += dp[i][j][1];
            if(check(i+1,j+1,2)) dp[i+1][j+1][2] += dp[i][j][1];

            //초기위치가 대각
            if(check(i,j+1,0)) dp[i][j+1][0] += dp[i][j][2];
            if(check(i+1,j,1)) dp[i+1][j][1] += dp[i][j][2];
            if(check(i+1,j+1,2)) dp[i+1][j+1][2] += dp[i][j][2];
        }
    }

    int sum = dp[n][n][0];
    sum += dp[n][n][1];
    sum += dp[n][n][2];

    cout << sum << "\n";

    return 0;
}