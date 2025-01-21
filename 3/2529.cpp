#include <bits/stdc++.h>
using namespace std;

int visited[10];
char m_[10];
int k;
string s;
int cnt = 0;
vector<int> v;
vector<string> sv;

bool check(int nx,int x) {
    char ch = m_[cnt];
    if(ch == '<') {
        if(x < nx) return true;
        else return false;
    }
    else if(ch == '>') {
        if(x > nx) return true;
        else return false;
    }
}



void dfs(int x) {
        if(s.size() == k+1) {
            sv.push_back(s);
            return;
        }
    for(int i = 0; i<= 9; i++) {
        int nx = i;
        if(visited[nx]) continue;
        if(check(nx,x)) {
            s += to_string(nx);
            cnt++;
            visited[nx] = 1;
            dfs(nx);
            visited[nx] = 0;
            s.pop_back();
            cnt--;
        }
        else continue;
    } 
}

int main() {
    cin >> k;
    for(int i = 0; i<k; i++) {
        cin >> m_[i];
    }

    for(int i = 0 ; i<=9 ; i++) {
        while(s.size()) {
            s.pop_back();
        }
        cnt = 0;
        visited[i] = 1;
        s += to_string(i);
        dfs(i);
        visited[i] = 0;
        s.pop_back();
    }

    sort(sv.begin(),sv.end());
    cout << sv[sv.size()-1]  << '\n';
    cout << sv[0] << "\n";


    return 0;
}