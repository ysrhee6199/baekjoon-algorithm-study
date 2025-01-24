#include "bits/stdc++.h"
using namespace std;
int tree_[54][54];
int node_num;
int del_node;
queue<int> q;
int visited[54];
int reef_node_cnt;
int root_node_num;

void bfs(int node)
{
    visited[node] = 1;
    q.push(node);
    bool root_node = true;
    while(q.size())
    {
        int current_node = q.front();
        q.pop();
        int reef_ = 0;
        for(int i = 0; i <node_num; i++ )
        {
            if(tree_[current_node][i])
            {
                if(!visited[i])
                {
                    reef_++;
                    q.push(i);
                    visited[i] = visited[current_node] + 1;
                }
            }
        }
        if(reef_ == 0) reef_node_cnt++;
    }
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> node_num;

    for(int i =0; i<node_num; i++) 
    {
        int tmp;
        cin >> tmp;
        if(tmp == -1) root_node_num = i;
        else tree_[tmp][i] = 1;
    }

    cin >> del_node;

    if(del_node == root_node_num)
    {
        cout << 0 << "\n"; return 0;
    }

    for(int i = 0; i< node_num; i++)
    {
        for(int j = 0; j<node_num ;j++)
        {
            tree_[i][del_node] = 0;
            tree_[del_node][j] = 0;
        }
    }

    if(node_num == 1) {
        cout << 1  << "\n";
        return 0;
    }
    

    bfs(root_node_num);

    cout << reef_node_cnt << "\n";
    return 0;
}