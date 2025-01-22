#include "bits/stdc++.h"
using namespace std;
string s;
int n;
stack<char> st_;
int main() 
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for(int j = 0; j<n; j++)
    {
        cin >> s;

        for(int i =0; i<s.size(); i++)
        {
            if(st_.size() == 0 ) st_.push(s[i]);
            else 
            {
                if(s[i] == ')' && st_.top() == '(') 
                {
                    st_.pop();
                }
                else st_.push(s[i]);
            }

        }

        if(st_.size()) cout << "NO" << "\n";
        else cout << "YES" << "\n";

        while(st_.size()){
            st_.pop();
        }
    }

}
