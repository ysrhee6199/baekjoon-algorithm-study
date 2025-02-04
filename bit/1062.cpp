#include "bits/stdc++.h"
using namespace std;
int n,k;
int a;
int words[54];

int count(int mask)
{
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        if((words[i] & mask) == words[i]) cnt++;
    }

    return cnt;
}

int go(int index, int k_ , int mask)
{
    if(k_<0) return 0;
    if(index == 26) return count(mask);
    int ret = go(index+1,k_-1,mask | (1 << index));
    if(index != 'a'-'a' && index != 'n'-'a' && index != 't'- 'a' && index != 'c'-'a' && index != 'i'-'a') 
    {
        ret = max(ret,go(index+1,k_,mask));
    }

    return ret;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    string s;
    for(int i =0; i<n;i++)
    {
        cin >> s;
        for(char c : s)
        {
            words[i] |= (int)(1 << (c - 'a'));
        }
    }

    cout << go(0,k,0) << "\n";

    return 0;
}