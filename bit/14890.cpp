#include "bits/stdc++.h"
using namespace std;
int n; //지도 크기 n x n;
int l; // 경사로의 크기
int a[104][104];
int b[104][104]; // 대칭 배열
int ret;

void solve(int aa[104][104])
{
    for(int i =0; i<n;i++)
    {
        int cnt = 1;
        int j;
        for(j =0;j<n-1;j++)
        {
            if(aa[i][j] == aa[i][j+1]) cnt++;
            else if(aa[i][j] + 1 == aa[i][j+1] && cnt >= l ) cnt = 1;
            else if(aa[i][j] - 1 == aa[i][j+1] && cnt >= 0) cnt = -l + 1;
            else break;
        }
        if( j == n - 1 && cnt >= 0) ret++;
    }
    return;
}

int main()
{
    cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);

    cin >> n >> l;
    for(int i =0; i<n;i++)
    {
        for(int j =0; j<n;j++)
        {
            cin >> a[i][j];
            //scanf("%d",&a[i][j]);
            b[j][i] = a[i][j]; // 대칭배열열
        }
    }

    solve(a);
    solve(b);

    cout << ret << "\n";
    return 0;

}