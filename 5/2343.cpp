#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[100004];
int left_, right_;
int sum, mx,ret;


bool check(int mid) {
    cout << mid << "mid" << '\n';
    if(mx > mid) return false; // 1 2 3 따로 담아야할경우 
    int temp = mid;
    int cnt = 0;
    for(int i = 0; i<n; i++) {
        if(mid - a[i] < 0 ){ 
            cout << a[i] <<  "\n";
            mid = temp;
            cnt++;
        }
        mid -= a[i];
    }
    if (mid != temp) {
        cnt++;
    }
    cout << cnt << "cnt" << '\n';
    return cnt <= m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i =0; i<n; i++) {
        cin >> a[i];
        sum += a[i];
        mx = max(mx,a[i]);
    }

    int lo = 0; 
    int hi = sum;

    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        if(check(mid)) {
            hi = mid -1;
            ret = mid;
        }else {
            lo = mid +1;
        }
    }

    cout << ret << "\n";

    return 0;

}