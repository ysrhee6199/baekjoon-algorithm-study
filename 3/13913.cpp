#include <bits/stdc++.h>
using namespace std;
int n,m;
int visited[100004];
int parent[100004];

int main() {
    cin >> n >> m;
    if(n == m) {
        cout << "0" << '\n';
        cout << n << '\n';
        return 0;
    }

    queue<int> q;
    visited[n] = 1;
    q.push(n);
    while(q.size()) {
        int now = q.front();
        q.pop();
        for(int next : {now -1, now+1,now*2}) {
            if(0 <= next && next <= 100000) {
                if(!visited[next]) {
                    visited[next] = visited[now] + 1; 
                    q.push(next);
                    parent[next] = now;
                }
            }
        }
    }
    vector<int> v;
    v.push_back(m);
    int m_tmp = m;
    while(true) {
        int tmp = parent[m_tmp];
        v.push_back(tmp);
        if(tmp == n) break;
        m_tmp = tmp;

    }

    cout << visited[m] - 1 << "\n";
    reverse(v.begin(),v.end());
    for(int i : v) {
        cout << i << ' ';
    }

    return 0;
}