#include <bits/stdc++.h>

using namespace std;
int n,m;
int temp;
int result = 987654321;
vector<pair<int,int>> home_;
vector<pair<int,int>> chick_;
vector<vector<int>> chlist_;

void combi(int start,vector<int> b) {
    if(b.size() == m) {
        chlist_.push_back(b);
        return;
    } 

    for(int i = start + 1; i< chick_.size(); i++) {
        b.push_back(i);
        combi(i,b);
        b.pop_back();
    }
    return;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i<n;i++) {
        for(int j = 0; j<n; j++) {
            cin >> temp;
            if(temp == 1 ) home_.push_back({i,j});
            else if(temp == 2) chick_.push_back({i,j});
        }
    }
    vector<int> v;
    combi(-1,v);

    for(vector<int> vec_ : chlist_) {
        int ret = 0;
        for(pair<int,int> home: home_) {
            int _min = 987654321;
            for(int idx_ :  vec_) {
                int abs_  = abs(home.first - chick_[idx_].first) + abs(home.second - chick_[idx_].second);
                _min = min(abs_,_min);
            }
            ret += _min;
        }
        result = min(result,ret);
    }
    
    cout << result << "\n";

    return 0;


}