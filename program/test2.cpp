#include <iostream>
#include <string>
using namespace std;
int main() {
    int N;
    string ye;
    string ba;
    string bi;
    string name;
    string subName;
    //const char* name_s;
    //const char* name_l;
    int  i;
    cin >> N;
    cin >> ye >> ba >> bi;
    while(cin >> name >> i)
    {
        if (i == 1)
        {
            subName = name.substr(0, ye.length());
            if (subName == ye)
                cout << name << endl;
            else
                cout << ye + name << endl;
        }
        else if (i == 2)
        {
            subName = name.substr(name.length() - ba.length());
            if (subName == ba)
                cout << name << endl;
            else 
                cout << name + ba << endl;
        }

        else if (i == 3)
        {
            subName = name.substr(0, bi.length());
            if (subName == bi)
                cout << name << endl;
            else
                cout << bi + name << endl;
        }
            
    }
    
    return 0;
        
}