#include <bits/stdc++.h>

using namespace std;
int num_;
string s;
int a[28];
bool check_ = false;
int main() {
    cin >> num_;
    for(int i = 0; i<num_;i++) {
        cin >> s;
        a[(int)s[0] - 'a'] += 1;
    }

    for(int i =0;i<27;i++) {
        if(a[i] >= 5) {
            cout << (char) (i + 'a');
            check_ = true;
        }
    }

    if(!check_) cout << "PREDAJA";
}