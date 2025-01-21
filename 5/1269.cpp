#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int na, nb;
map<int,int> mp_;
int main() {
    cin >> na >> nb;

    for(int i = 0; i<na; i ++) {
        int tmp;
        cin >> tmp;
        mp_[tmp]++;
    }

    for(int i = 0; i<nb; i ++) {
        int tmp;
        cin >> tmp;
        mp_[tmp]++;
    }

    int cnt = 0;
    for(auto it : mp_) {
        if(it.second == 1) cnt++;
    }

    cout << cnt << "\n";

    return 0;
}
