#include "bits/stdc++.h"
using namespace std;
/*0666 1666 2666 3666 4666 5666 6661 6662 6663 6664 6665 6666 6667 6668 6669 7666 8666 9666*/
int num;
int main() 
{
    cin >> num;
    int i = 666;

    for(;;i++)
    {
        if(to_string(i).find("666") != string::npos) num--;
        if(num == 0) break;
    }

    cout << i <<"\n";

    return 0;
}