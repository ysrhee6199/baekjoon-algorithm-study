#include <bits/stdc++.h>
using namespace std;
int cnt;
int n;
int start_,end_;
vector<pair<int,int>> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i =0; i<n; i++) {
        cin >> start_ >> end_;
        v.push_back({end_,start_});
    }

    sort(v.begin(),v.end());
    
    int start_time = 0;
    int end_time = -1;

    for(int i = 0; i<v.size(); i++) {
        if(v[i].second >= end_time) {
            start_time = v[i].second;
            end_time = v[i].first;
            cnt++;
        }
    }

    cout << cnt << "\n";
    return 0;
}