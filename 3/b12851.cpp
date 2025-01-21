#include <bits/stdc++.h>

using namespace std;
int n,m;
int visited[100004];
int cnt[100004];
int main(){
    cin >> n >> m;
    if(n == m) {
        cout << "0" << '\n';
        cout << "1" << '\n';
        return 0;
    }

    queue<int> q;
    visited[n] = 1;
    cnt[n] = 1;
    q.push(n);
    while(q.size()) {
        int an = q.front();
        q.pop();
        for(int nn : {an - 1,an+1,an*2}) {
            if( 0 <= nn && nn <= 100000) {
                if(!visited[nn]) {
                    q.push(nn);
                    visited[nn] = visited[an] + 1;
                    cnt[nn] += cnt[an];
                }
                else if (visited[nn] == visited[an] + 1) {
                    cnt[nn] += cnt[an];
                }
            }

        }
    }

    cout << visited[m] -1 << "\n";
    cout << cnt[m] << "\n";
    return 0;
    
}