#include <bits/stdc++.h>

using namespace std;


int num_;
vector<string> sv;
int main() {
    string s;
    cin >> num_;
    cin >> s;

    auto it = s.find('*');
    string s1 = s.substr(0,it);
    s.erase(0,it+1);
    
    for(int i =0;i<num_;i++) {
        string input_;
        cin >> input_;
        sv.push_back(input_);
    }

    for(int i =0; i<num_;i++) {
        if(sv[i].size() < s1.size() + s.size()) {
            cout << "NE" << '\n';
            continue;
        }
        string s1input_ = sv[i].substr(0,s1.size());
        string s2input_ = sv[i].substr(sv[i].size() - s.size());
        if(s1input_ != s1 || s2input_ != s) {
            cout << "NE" << '\n';
            continue;
        }

        cout << "DA" << '\n';
    }


    return 0;
}