#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// "정렬된" 배열에서 어떤 값이 나오는 첫번째 지점 또는 초과하는 지점의위치를 찾으려면?(이분탐색)

int main() {
    vector<int> a {1,2,3,4,5,6,7};
    cout << lower_bound(a.begin(),a.end(),3) - a.begin() << '\n';
    cout << upper_bound(a.begin(),a.end(),3) - a.begin() << '\n';
}