#include <bits/stdc++.h>

using namespace std;

int main() {
    cout << "**************************************************" << '\n';
    cout << "atoi(s.c_str()) 은 const char * s를 정수 int로 변환하는 방법 정수가 아니면 0을 반환" << endl;  

    string s = "1";
    string s2 = "amumu";
    cout << atoi(s.c_str()) << '\n';
    cout << atoi(s2.c_str()) << '\n';

    cout << "**************************************************" << '\n';
    cout << "stoi() 는 string을 받아 int로 변환" << endl; 
    string s3 = "1234";
    int num = stoi(s3);
    cout << num << '\n'; 
    return 0;  
}