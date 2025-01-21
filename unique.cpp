#include <bits/stdc++.h>
using namespace std;
vector<int> v;

//unique는 범위안의 있는 요소 중 중복되는 요소를 제거하고 나머지 요소들은 삭제하지 않고 그대로 둠

int main() {
    for(int i = 1; i <= 5; i++){
        v.push_back(i);
        v.push_back(i);
    }
    for(int i : v) cout << i << " ";
    cout << '\n';

    auto it = unique(v.begin(),v.end());
    cout << it - v.begin() << '\n';
    for(int i : v) cout << i << " ";
    cout << '\n';

    //unique는 sort와 erase(unique()) 와 함께 쓰는것이 좋음

    vector<int> s {4,3,3,5,1,2,3};
    s.erase(unique(s.begin(),s.end()),s.end());
    for(int i : s) cout << i << " ";
    cout << '\n';

    vector<int> s2{4,3,3,5,1,2,3};
    sort(s2.begin(),s2.end());
    s2.erase(unique(s2.begin(),s2.end()),s2.end());
    for(int i : s2) cout << i << " ";
    cout << '\n';
}