#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;
    vector<pair<ll,ll>> bosuk_(n);
    for(int i = 0; i<n; i++) {
        cin >> bosuk_[i].first >> bosuk_[i].second; //무게,value
    }
    vector<ll> bag_(k);
    for(int i =0; i<k; i++) {
        cin >> bag_[i];
    }

    sort(bosuk_.begin(),bosuk_.end()); // 무게 내림차순
    sort(bag_.begin(), bag_.end()); // 가방 크기 내림차순

    priority_queue<ll> pq;
    int j = 0;
    for(int i =0; i<k; i++) {
        while(j<n && bosuk_[j].first <= bag_[i]) pq.push(bosuk_[j++].second); //가방에 담을 수 있는 모든 보석을 pq에 넣음
        if(pq.size()) {
            ret += pq.top();
            pq.pop();
        } // 그중 가장큰 보석 갯
    }

    cout << ret << "\n";
    return 0;
    

}