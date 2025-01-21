#include <bits/stdc++.h>

using namespace std;
int a[100];
int main() {
    string s;
    cin >> s;

    for(int i =0;i<s.size(); i++) {
        int cnt = (int)s[i] - 'a';
        a[cnt]+=1;
    }

    for(int i =0; i<26;i++) {
        cout << a[i] << ' ';
    }
}