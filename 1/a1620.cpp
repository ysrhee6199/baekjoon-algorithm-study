#include <bits/stdc++.h>

using namespace std;

int n,m;
map<string,string> mp;

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 향상
    cin.tie(NULL);
    cin >> n >> m;

    for(int i =0;i<n;i++) {
        string s;
        cin >> s;
        string in = to_string(i+1);
        mp.insert({in,s});
        mp.insert({s,in});
    }

    for(int i = 0;i<m;i++) {
        string input_;
        cin >> input_;
        cout << mp[input_] << '\n';
    }

    return 0;
}