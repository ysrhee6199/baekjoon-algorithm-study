#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[300004];
ll ret = 1e18;

bool check(ll mid) {
    ll num = 0;
    for(int i = 0; i<m; i++) {
        num += a[i] / mid;
        if(a[i]%mid) num++; // 나누어 떨어지지 않으면 1명더 줄 수 있음
    }

    return n >= num; 
}

int main() {
    cin >> n >> m;

    ll lo = 1, hi = 0, mid;
    for(int i = 0; i < m; i++) {
        cin >> a[i];
        hi = max(hi,a[i]);
    }

    while(lo <= hi) {
        mid = (lo + hi) / 2;
        if(check(mid)) {
            ret = min(ret,mid);
            hi = mid -1;
        }
        else {
            lo = mid + 1;
        }
    }

    cout << ret << "\n";
    return 0;
}