#include <bits/stdc++.h>

using namespace std;

vector<int> v;
int n = 9, k =7;


int main() {

    for(int i = 0; i <n ; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(),v.end(),less<int>());
    do{
        int sum =  0;
        for(int i =0;i<k;i++) sum+=v[i];
        if(sum==100) {
            break;
        }
    }while(next_permutation(v.begin(),v.end()));
    for(int i =0;i<k;i++) cout << v[i] << '\n';

    return 0;
}