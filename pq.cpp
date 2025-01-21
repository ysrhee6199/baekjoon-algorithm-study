#include <bits/stdc++.h>

using namespace std;

priority_queue<int,vector<int>,greater<int> > pq;
priority_queue<int> pq2;
priority_queue<int,vector<int>,less<int> > pq3;

struct Point {
    int y, x;
};

struct cmp {
    bool operator()(Point a, Point b) {
        return a.x > b.x;
    }
};


 priority_queue<Point, vector<Point>, cmp> pq4;
int main() {
    for(int i =5; i >= 1; i--) {
        pq.push(i);
        pq2.push(i);
        pq3.push(i);
    }

    while(pq.size()) {
        cout << pq.top() << " : " << pq2.top() << " : " << pq3.top() << '\n';
        pq.pop();
        pq2.pop();
        pq3.pop();
    }
pq4.push({1, 1});
 pq4.push({2, 2});
 pq4.push({3, 3});
 pq4.push({4, 4});
 pq4.push({5, 5});
 pq4.push({6, 6});
 cout << pq4.top().x << "\n";
 return 0;

}