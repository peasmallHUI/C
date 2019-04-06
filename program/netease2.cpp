#include <iostream>
#include <string> 

using namespace std;

string dec2bi (string str);
string bi2char (string str);

int main()
{
    int T;
    int flag = 0;
    string nstr;
    cin  >> T;
    
    while(cin >> nstr)
    {
        int cn;
        string result;
        cn = nstr.length()/3 + 1;
        string* sptr;
        sptr = new string[cn];
        sptr[0] = nstr.substr(0,nstr.length()%3);
        for (int  j = 1; j < cn; j++)
        {
            sptr[j] = nstr.substr(nstr.length()%3 + (j-1)*3,3);
        }
        if (nstr.length()%3 == 0)
                flag = 1;
        for (int j = flag; j < cn; j++)
        {
            //cout << j << "#" << sptr[j] << endl;
            
            sptr[j] = dec2bi(sptr[j]);
            //cout << j << "#" << sptr[j] << endl;
            result += bi2char(sptr[j]);
        }
        cout << result << endl;
    }

    return 0;
}

string dec2bi (string str)
{
    int num = 0;
    int i;
    int j;
    string strp;
    char temp;
    for ( i = 0; i < str.size(); i++)
    {
        num = num*10 + str[i] - '0';
    }
    for (j = 0 ; num; j++)
    {
        temp = num%2 + '0';
        strp = temp + strp;
        num /= 2;
    }
    return strp;
}

string bi2char (string str)
{
    int num = 0;
    int i;
    string temp[2];
    string res;
    char t;
    if (str.length() <= 5)
    {
        temp[0] = str.substr(0, str.length());

        for (i = 0; i < temp[0].length();i++)
        {
            num = num*2 + temp[0][i] - '0';
        }
        if (num < 10)
        {
            t = num + '0'; 
        }
        else
        {
            t = num + 'A' - 10;
        }
        res = t;
    }
    else
    {
        
        temp[0] = str.substr(0, str.length()-5);
        temp[1] = str.substr(str.length()-5);
        //cout << temp[0] << '#' << temp[1] << endl;
        for (i = 0; i < temp[0].length();i++)
        {
            num = num*2 + temp[0][i] - '0';
        }
        if (num < 10)
        {
            t = num + '0'; 
        }
        else
        {
            t = num + 'A' - 10;
        }
        res = t;
        //cout << res << 1<<endl;
        num = 0;
        for (i = 0; i < temp[1].length();i++)
        {
            num = num*2 + temp[1][i] - '0';
        }
        if (num < 10)
        {
            t = num + '0'; 
        }
        else
        {
            t = num + 'A' - 10;
        }
        res += t;
        //cout << res << 2 <<endl;
    }
    return res;
}