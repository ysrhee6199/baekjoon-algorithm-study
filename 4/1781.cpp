#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> v;
priority_queue<int,vector<int>,greater<int>> pq;
int n;
int dead_,cup_;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i<n;i++) {
        cin >> dead_ >> cup_;
        v.push_back({dead_,cup_});
    }

    sort(v.begin(),v.end());

    for(int i = 0; i<v.size(); i++) {
        pq.push(v[i].second);
        if(pq.size() > v[i].first){
            pq.pop();
        }
    }
    int sum = 0;
    while(pq.size()) {
        sum += pq.top();
        pq.pop();
    }

    cout << sum << '\n';

    return 0;
}