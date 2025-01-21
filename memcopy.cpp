#include <bits/stdc++.h>

using namespace std;

//어떤 변수를 깊은 복사 할때 memcpy() 와 copy() 사용
// memcpy()는 Array끼리 복사할때 copy()는 arrary vecotr 모두 사용가능

int main() {


    // memcpy는  어떤 변수의 메모리에 있는 값들을 다른 변수의 특정 메모리값으로 복사할때
    //void * memcpy ( void * destination, const void * source, size_t num );
    int v[3]={1,2,3};
    int ret[3];
    memcpy(ret,v,sizeof(v));
    cout << ret[1] << '\n';
    ret[1] = 100;
    cout << ret[1] << '\n';
    cout << v[1] << '\n';
    //vector를 복사할경우 깊은 복사가 이뤄지지 않음

    //copy(v.begin(), v.end(), ret.begin());

    vector<int> v1{1,2,3};
    vector<int> ret2(3);

    copy(v1.begin(),v1.end(),ret2.begin());
    cout << ret[1] << '\n';
    return 0;
}