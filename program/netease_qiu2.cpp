#include <iostream>
#include <string>
using namespace std;

int main()
{
	int T;
	string str;
	string res;
	cin >> T ;
	while (getline(cin, str))
	{
		int i = 0;
		res = "";
		int M = 0;
		while (str[i])
		{
			char curChar = str[i];
			res += curChar;
			i++;
			if (curChar + 1 == str[i])
			{
				M += 1;
			}
			else
			{
				if (M >= 3)
				{
					res = res.substr(0, res.length() - M);
					res += '-';
					res += str[i - 1];
				}					
				M = 0;
			}
		}

		cout << res << endl;
	}
	return 0;
}