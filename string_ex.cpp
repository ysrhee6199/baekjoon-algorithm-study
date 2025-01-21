#include <bits/stdc++.h>

using namespace std;

vector<string> split(const string& input, string delimiter) {
    vector<string> result;
    auto start = 0;
    auto end = input.find(delimiter);
    while(end != string::npos) {
        result.push_back(input.substr(start,end-start));
        start = end + delimiter.size();
        end = input.find(delimiter,start);
    }
    result.push_back(input.substr(start));
    return result;
}


int main()
{
    string a = "love is";
    a += " pain!";
    cout << a << " : " << a.size() << "\n";
    a.pop_back();
    cout << a << " : " << a.size() << "\n";

    cout << char(* a.begin()) << '\n';
    cout << char(* (a.end()-1)) << '\n';
    a.insert(0,"test ");
    cout << a << " : " << a.size() << "\n";
    a.erase(0,5);
    cout << a << " : " << a.size() << "\n";

    auto it = a.find("love");
    if (it != string::npos) {
        cout << "포함되어 있다." << '\n';
    }
    else {
        cout << "포함되어 있지 않아"<<'\n';
    }

    cout << it << '\n';
    cout << string::npos << '\n';

    cout << a.substr(5,2) << '\n';


    cout << "**************************************************" << '\n';
    cout << "string 의 push_back 은 문자 하나씩 밖에 못넣는다." << '\n';
    string s = "Hello";
    s.push_back(' ');
    s.push_back('W');
    s.push_back('o');
    s.push_back('r');
    s.push_back('l');
    s.push_back('d');

    cout << s << '\n';


    cout << "**************************************************" << '\n';
    cout << "substr(위치,크기) => 특정 위치에서 크기만큼 문자열 추출 O(n)의 시간복잡도" << endl;
    cout << "크기를 넣지 않는다면 위치로부터 문자열 가장 끝자리까지 문자열을 추출합니다." << endl;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a2 = "aaabbb";
    string b = a2.substr(2);
    cout << b << '\n';


    cout << "**************************************************" << '\n';
    cout << "아스키 코드 97 : a / 65 : A" << endl;
    char a3 = 'a';
    cout << (int)a3 << '\n';

    cout << "**************************************************" << '\n';
    cout << "reverse 를 사용한 문자열 뒤집기" << endl;
    string a4 ="It's hard to have a sore leg";
    reverse(a4.begin(),a4.end());
    cout << a4 << '\n';
    reverse(a4.begin(),a4.end());
    cout << a4 << '\n';
    reverse(a4.begin()+3,a4.end());
    cout << a4 << '\n';


    cout << "**************************************************" << '\n';
    cout << "문자열 split은 구현해야함" << endl;
    cout << ",를 기반으로 split" << endl;
    string str = "apple,banana,orange,grape";
    vector<string> fruits = split(str,",");
    for (const string& fruit : fruits) {
        cout << fruit << '\n';
    }

    return 0;
}