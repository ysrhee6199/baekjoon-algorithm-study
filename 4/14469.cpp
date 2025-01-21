#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int,int>> v;
int main() {
    cin >> n;
    int arrival_time = 0;
    int check_time = 0;
    for(int i =0; i<n;i++) {
        cin >> arrival_time >> check_time;
        v.push_back({arrival_time,check_time});
    }

    sort(v.begin(),v.end());
    int duration_ = 0;
    for(int i = 0; i<v.size(); i++) {
        if(v[i].first >= duration_) {
            duration_ = v[i].first;
        }
        duration_ += v[i].second;
    }

    cout << duration_ << "\n";

    return 0;

}