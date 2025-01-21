#include <bits/stdc++.h>
using namespace std;
int t,w;
int dp[1004][2][34]; // 몇초,움직이는 경우의수,몇번
int b[1004];

int go(int idx, int tree, int cnt) {
    if(cnt < 0) return -1e9; //기저
    if(idx == t) return cnt == 0 ? 0 : -1e9;

    //메모이제이션
    int &ret = dp[idx][tree][cnt];
    if(~ret) return ret; // 음수가 아니라면

    return ret = max(go(idx+1,tree^1,cnt-1),go(idx+1,tree,cnt)) + (tree == b[idx] - 1); // 1^1 = 0 , 0^1 = 1

}

int main() {
    memset(dp,-1,sizeof(dp));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t >> w;
    for(int i = 0; i<t; i++) {
        cin >> b[i]; // 초 마다 몇번째 나무에서 자두가 떨어지는 지
    }

    cout << max(go(0,1,w - 1), go(0,0,w)) << "\n"; // 움직이는 경우, 안움직이는 경우
    return 0;
}