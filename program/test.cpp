#include <iostream>

using namespace std;

int main()
{
    int N;
    int i;
    cin >> N;
    int Y ;
    int D ;
    while(cin >> Y >> D)
    {
        int flag = (Y%400 == 0) || ( (Y % 4 == 0) && (Y % 100 != 0) );
        if(D >= 31)
             cout << 0;
        else if(D == 30)
            cout << 7;
        else if (D == 29)
            cout << 11;
        else if (D == 28) 
            cout << 11 + flag;
        else 
            cout << 12;
    }
    return 0;
}