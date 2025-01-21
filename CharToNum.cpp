#include <bits/stdc++.h>

using namespace std;

int main() {
    char a = 'a';
    cout << (int)a << '\n';
    cout << (int)a - 97 << '\n';
    cout << (int)a - 'a' << '\n';

    string s = "123456";
    vector<int> digits;
    for(int i = 0; i< s.length();i++) {
        int digit = s[i] - '0';
        digits.push_back(digit);
    }
    cout << "문자열을 개별 숫자로 변환한 결과" << '\n';
    for(int i =0; i< digits.size(); i++) {
        cout << digits[i] << " ";
    }

    return 0;
}