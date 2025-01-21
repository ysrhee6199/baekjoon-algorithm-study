#include <bits/stdc++.h>

using namespace std;

//fill()과 memset()은 배열을 초기화할때 씀
//fill은 모든 값으로 초기화 가능하지만 memset은 -1,0만 가능
//memset이 더 빠름

//fill()은 fill(시작값,끝값,초기화하는값) [first,last) 까지 val로 초기화

int a[10];
int b[10][10];
char a2[1004];
int main() {
    fill(&a[0],&a[10],100);
    for(auto i : a) {
        cout << i << " ";
    }
    cout << '\n';
    fill(&b[0][0], &b[9][10],2);
    for(int i =0; i< 10;i++) {
        for(int j = 0;j<10;j++) {
            cout << b[i][j] << " ";
        }
        cout << '\n';
    }

    //다음 코드처럼 배열의 ㅣ름을 기반으로 초기화 가능
    fill(a,a+10,2);

    //memset() 은 0,-1, char형 문자 하나 만 초기화할때 사용


    memset(a2,'a',sizeof(a2));
    for(auto i : a2) {
        cout << i<< ' ';
    }
    cout <<'\n';

    return 0;
}