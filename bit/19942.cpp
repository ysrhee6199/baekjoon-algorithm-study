#include "bits/stdc++.h"
using namespace std;

int n;
int mp,mf,ms,mv;
int p_[17], f_[17], s_[17], v_[17], c_[17];
int ret = 987654321;
int ret_s =2100000;
map<int,vector<vector<int>>> mp_;
int main()
{
    cin.tie(NULL), cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    cin >> mp >> mf >> ms >> mv;
    for(int i = 0; i<n;i++)
    {
        cin >> p_[i] >> f_[i] >> s_[i] >> v_[i] >> c_[i];
    }

    for(int i =0; i< (1<<n); i++)
    {
        int p_sum = 0;
        int f_sum = 0;
        int s_sum = 0;
        int v_sum = 0;
        int c_sum = 0;
        vector<int> v;
        for(int j = 0; j<n;j++)
        {
            if(i & (1 << j))
            {
                v.push_back(j);
                p_sum += p_[j];
                f_sum += f_[j];
                s_sum += s_[j];
                v_sum += v_[j];
                c_sum += c_[j];
            }
        }   
        if(p_sum >= mp && f_sum >= mf && s_sum >= ms && v_sum >= mv)
        {
            if (c_sum <= ret)
            {
                ret = c_sum;
                mp_[ret].push_back(v);
            }

        }
    }

    if(ret == 987654321) cout << -1 << "\n";
    else 
    {
        cout << ret <<"\n";
        sort(mp_[ret].begin(), mp_[ret].end());
        for(int i : mp_[ret][0])
        {
            cout << i+1 << " ";
        }
        cout << "\n";
    }

    return 0;
}

