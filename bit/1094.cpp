#include "bits/stdc++.h"
using namespace std;
int x; // 막대길이이
// x 보다 크면
//반으로 자름 
// 반으로 잘린게 x 보다 크면 버림
vector<int> v;
int ret;

int check()
{
    int size_ = v.size();
    for(int i =0; i<(1 << size_); i++)
    {
        int sum = 0;
        int ret_tmp = 0;
        for(int j =0; j<size_; j++)
        {
            if(i & ( 1 << j))
            {
                sum += v[j];
                ret_tmp++;
            }
        }
        if(sum == x)
        {
            return ret_tmp;
        }

    }

    return 0;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> x;
    int min_x = 64;
    int cnt = 1;
    while(true)
    {
        if(min_x == x) 
        {
            cout << 1 << "\n";
            return 0;
        }
        else if(min_x > x )
        {
            min_x /= 2;
        }
        else if(min_x < x)
        {
            v.push_back(min_x);
            v.push_back(min_x);
            cnt = 2;
            break;
        }
    }

    while(true)
    {
        int check_value = check();
        if(check_value){
            cout << check_value << "\n";
            return 0;
        } 
        else{
            int tmp = v.back() / 2;
            v.pop_back();
            v.push_back(tmp);
            v.push_back(tmp);
        }
    }


}