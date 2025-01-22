#include "bits/stdc++.h"
using namespace std;

int main() 
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);


    while(true)
    {
        string s;
        getline(cin,s);
        if(s==".") break;

        
        stack<char> st_;
        for(int i =0; i<s.size(); i++)
        {
            if(s[i] == '(' || s[i] == '[') st_.push(s[i]);
            else if (s[i] == ')' || s[i] == ']')
            {
                if(st_.empty()) st_.push(s[i]);
                else if(s[i] == ')' && st_.top() == '(') st_.pop();
                else if(s[i] == ']' && st_.top() == '[') st_.pop();
                else st_.push(s[i]);
            }
            
        }

        if(st_.empty()) cout << "yes" << "\n";
        else cout << "no"  << "\n";
    }

    return 0;
}