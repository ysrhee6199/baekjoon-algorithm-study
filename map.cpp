#include <bits/stdc++.h>

using namespace std;

map<string,int> mp;

string a[] = {"주홍철","이승철","박종선"};

int main() {
    for(int i =0; i<3;i++) {
        mp.insert({a[i],i+1});
        mp[a[i]] = i+1;
    }

    mp["kundol"] = 4;

    cout <<mp.size() <<endl;

    mp.erase("kundol");

    cout <<mp.size() <<endl;

    auto it = mp.find("kundol");
    if(it == mp.end()) {
        cout << "못찾겠다 꾀꼬리\n";
    }

    mp["kundol"] = 100;
    it = mp.find("kundol");
    if(it != mp.end()) {
        cout << (*it).first << ": " << (*it).second << "\n";
    }

    for(auto i : mp) {
        cout << i.first << ": " << i.second << '\n';
    }
    mp.clear();
    return 0;
}