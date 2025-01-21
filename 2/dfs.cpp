#include <bits/stdc++.h>
using namespace std;

const int n = 6;
vector<int> adj[n];
int visited[n];

void dfs(int a) {
    visited[a] = 1;
    cout << a << "\n";
    for(auto i : adj[a]) {
        if(visited[i] == 0) {
            dfs(i);
        } 
    }
    cout << a << "로부터 시작된 함수가 종료되었습니다." << "\n";
    
} 


int main() {
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[4].push_back(2);
    adj[2].push_back(5);
    dfs(1);
}