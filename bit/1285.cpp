#include "bits/stdc++.h"
using namespace std;
const int INF = 987654321;
int a[44];
int n;
int ret_ = 987654321;

void go(int idx)
{
    if(idx == n+1)
    {
        int sum  = 0;
        for(int i = 0; i<n; i++)
        {
            int h_cnt = 0;
            int t_cnt = 0;
            for(int j =1; j<=n; j++)
            {
                if(a[j] & ( 1 << i))
                {
                    t_cnt++;
                }
                else
                {
                    h_cnt++;
                }
            }
            sum += min(t_cnt,h_cnt);
        }
        ret_ = min(ret_,sum);
        return;
    }

    go(idx+1);
    a[idx] = ~a[idx];
    go(idx+1);
    a[idx] = ~a[idx];
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;

    for(int i =1; i <=n;i++)
    {
        string s;
        cin >> s;
        int value = 1;
        for(int j=0; j<s.size();j++)
        {
            if(s[j] == 'T')
            {
                a[i] |= value;
            }
            value*=2;
        }
    }

    go(1);

    cout << ret_ << "\n";

    return 0;

}     