#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

ll test_case;

ll do_test(ll a) 
{
    ll b = 5;
    ll result = 0;
    while(a >= b)
    {
        result += a/b;
        b *=5;
    }

    return result;
}

int main() 
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> test_case;

    for(ll i =0; i <test_case; i++)
    {
        ll test = 0;
        cin >> test;

        ll cnt;

        cnt = do_test(test);
        cout << cnt << "\n";


    }
    return 0;
}