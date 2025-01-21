#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
ll n,m;
ll a[100004];
ll max_m,sum;
bool check(ll mid) {
    ll cnt = 1;
    ll temp = mid;
    for(int i = 0; i<n;i++) {
        if(mid - a[i] < 0) {
            cnt++;
            mid = temp;
        }
        mid -= a[i];
    }

    return cnt <= m;
} 

int main() {
    cin >> n >> m;

    for(int i = 0; i<n; i++) {
        cin >> a[i];
        max_m = max(a[i],max_m);
    }

    ll lo = max_m;
    ll hi = 1000000004;
    ll ret = -1;
    while(lo <= hi) {
        int mid = (lo + hi) /2;
        if(check(mid)) {
            ret = mid;
            hi = mid -1;
        }
        else{
            lo = mid + 1;
        }
    }

    cout << ret << "\n";

    return 0;
}