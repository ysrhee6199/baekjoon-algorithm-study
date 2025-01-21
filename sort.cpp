#include <bits/stdc++.h>
using namespace std;

//sort(first, last, *커스텀비교함수)

vector<int> a;
int b[5];
vector<pair<int, int>> v;

bool cmp(pair<int,int> a, pair<int,int>b) {
    return a.first > b.first;
}

int main() {
    for(int i = 5; i >= 1; i--) b[i - 1] = i;
    for(int i = 5; i >= 1; i--) a.push_back(i);


    sort(a.begin(),a.end(),less<int>());
    sort(b,b+5,less<int>());
    for(int i : b) cout << i << ' ';
    cout << '\n';
    for(int i : a) cout << i << ' ';
    cout << '\n';

    sort(a.begin(),a.end(),greater<int>());
    sort(b,b+5,greater<int>());
    for(int i : b) cout << i << ' ';
    cout << '\n';
    for(int i : a) cout << i << ' ';
    cout << '\n';

    //pair기반으로 만들어진 vector의 경우 따로 설정하지 않으면 first,second 순으로 차례차례 오름차순
    for(int i =10;i>=1;i--) {
        v.push_back({i,10-i});
    }
    sort(v.begin(),v.end());
    for(auto it : v) cout << it.first << " : " << it.second << "\n";
    // first는 내림차순 second는 오름차순으로 정렬하고 싶다면 커스텀 비교함수 필요

    // > 내림차순 < 오름차순
    sort(v.begin(),v.end(),cmp);
    for(auto it : v) cout << it.first << " : " << it.second << "\n";
}