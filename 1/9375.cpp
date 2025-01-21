#include <bits/stdc++.h>

using namespace std;


int n,m;
int main() {
    cin >> n;

    for(int i =0; i<n;i++) {
        cin >> m;
        map<string,int> mp;
        for (int j =0;j<m;j++) {
            string s;
            cin >> s >> s;
            mp[s]++;
        }
        long long sum = 1;
        for(auto i : mp) {
            sum *= i.second + 1;
        }
        cout << sum-1 << '\n';
    }
}