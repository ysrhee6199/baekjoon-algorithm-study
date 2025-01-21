#include <bits/stdc++.h>

using namespace std;

pair <int,int> pi;
tuple <int,int,int> tl;
int a,b,c;

int main() {
    cout << "**************************************************" << '\n';
    cout << "pair는 first와 second 라는 멤버변수를 가지는 클래스이며 두가지 값을 담아야 할 때씁니다. tuple은 세가지 이상의 값을 담을 때 쓰는 클래스" << endl;    

    pi = {1,2};
    tl = make_tuple(1,2,3);
    tie(a,b) = pi;
    cout << a << " : " << b << '\n';

    tie(a,b,c) = tl;
    cout << a << " : " << b << " : " << c << '\n';

    a = pi.first;
    b = pi.second;
    cout << a << " : " << b << '\n';
    return 0;
}