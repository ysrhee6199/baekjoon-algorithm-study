#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> pd;
priority_queue<int,vector<int>,greater<int>> pq;
int n;
int money,day;
int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> money >> day;

        pd.push_back({day,money});
    }
    
    sort(pd.begin(),pd.end());

    for(int i = 0; i<n; i++) {
        pq.push(pd[i].second);
        if(pq.size() > pd[i].first) {
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