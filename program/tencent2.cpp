#include <iostream>
#include <string>
using namespace std;
int string2num (string str, int t);

int main()
{
    string num1;
    string num2;
    string num3;
    int sum = 0;
    int ans1;
    int ans2;
    int ans3;
    int all[20] = {0};
    int k = 0;
    int flagp;
    int flage;
    string  fomula;

    cin >> fomula;
    flagp = fomula.find('+');
    flage = fomula.find('=');
    num1 = fomula.substr(0,flagp);
    num3 = fomula.substr(flage+1);
    num2 = fomula.substr(flagp+1,fomula.length() - 2 - num1.length() - num3.length());

    //cout << num1 << num2 << num3 << endl;

    for (int i = 2; i <= 20; i++)
    {
        ans1 = string2num(num1,i);
        ans2 = string2num(num2,i);
        ans3 = string2num(num3,i);

        //cout << ans1 << "#" << ans2 << "#" << ans3 << endl; 
        if ( (ans1 > 0 && ans2 > 0 && ans3 > 0) && ((ans1 + ans2) == ans3) )
        {
            sum++;
            all[k++] = i;
        }
        
    }
    cout << sum << endl;
    for (int i = 0; i < k; i++)
    {
        cout << all[i] << endl;
    }
    return 0;
}

int string2num (string str, int t)
{
    int ans = 0;
    char w;
    bool flag = 0;
    for (int i = 0; i < str.size(); i++)
    {
        
        w = str[i];
        //cout << flag <<endl;
        if ( w >= '0' && w <= '9')
        {
            if ( w -'0'>= t)
                flag = 1;
            ans = ans * t + w - '0';
        }
        if (w >= 'A' && w <= 'Z')
        {
            if( w - 'A' + 10 >= t)
                flag = 1;
            ans = ans * t + w - 'A' + 10;
        }
    }
    if (flag)
        ans = -1;
    return ans;
}
