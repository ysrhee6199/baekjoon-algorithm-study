#include "bits/stdc++.h"
using namespace std;

int x;
int ret = 1;
int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> x;

     while( x != 1)
     {
        if(x & 1) ret++;
        x /= 2;
     }

     cout << ret << "\n";

     return 0;
}