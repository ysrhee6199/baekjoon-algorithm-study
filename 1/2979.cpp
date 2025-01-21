#include <bits/stdc++.h>

using namespace std;
int a,b,c;
int d[105];
int main() {
    cin >> a >> b >> c;
    for(int i =0;i<3;i++) {
        int start_ = 0;
        int end_ = 0;
        cin >> start_ >> end_;

        for(int i = start_; i< end_;i++) {
            d[i] += 1;
        }
    }
    int sum = 0;
    for(int i =0; i<102 ;i++) {
        if(d[i] == 0) continue;
        else if(d[i] == 1) sum  = sum + d[i]*a;
        else if(d[i] == 2) sum = sum + d[i]*b;
        else if(d[i] == 3) sum = sum + d[i]*c;
    }

    cout << sum;
}