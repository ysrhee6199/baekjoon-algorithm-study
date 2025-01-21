#include <bits/stdc++.h>

using namespace std;

int a[100009];
int k;
vector<int> v;
int main() {
    int n;
    cin >> n >> k;

    for(int i =0;i<n;i++) {
        cin >> a[i];
    }
    int sum = 0;
    for(int i =0;i<n;i++) {
        if(i < k-1){
            sum += a[i];
        }
        else if( i == k-1) {
            sum += a[i];
            v.push_back(sum);
        }
        else {
            sum -= a[i-k];
            sum += a[i];
            v.push_back(sum);
        }
    }

    int ret_ = *max_element(v.begin(),v.end());

    cout << ret_;

    return 0;   
}