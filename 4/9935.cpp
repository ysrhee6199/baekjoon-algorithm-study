#include <bits/stdc++.h>
using namespace std;

string s1,s2;
stack<char> st;

int main() {
    cin >> s1;
    cin >> s2;

    for(int i = 0 ; i<s1.size(); i++) {
        st.push(s1[i]);

        if(st.size() >= s2.size() && st.top() == s2[s2.size()-1]) {
            string ss;
            for(char c : s2) {
                ss += st.top();
                st.pop();
            }

            reverse(ss.begin(),ss.end());
            if(ss != s2) {
                for(char c : ss) {
                    st.push(c);
                }
            }
        }
    }

    string ss;
    while(st.size()) {
        ss += st.top();
        st.pop();
    }

    if(ss.size()) {
        reverse(ss.begin(),ss.end());
        cout << ss << "\n";
    }
    else {
        cout << "FRULA" << "\n";
    }

    return 0;


}