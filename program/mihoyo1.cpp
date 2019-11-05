#include <iostream>
#include <string>
using namespace std;

int main()
{
	string strtemp = "";
	char ctemp;
	int icnt = 0;
	int totalcnt[26] = { 0 };
	int i = 0;

	while (cin >> ctemp)
	{
		if (ctemp >= '0' && ctemp <= '9')
		{
			icnt = ctemp - '0';
			i = 0;
			for (i = 0; i < strtemp.length(); i++)
			{
				if (strtemp[i] >= 'a' && strtemp[i] <= 'z')
					totalcnt[int(strtemp[i] - 'a')] += icnt;
				else if(strtemp[i] >= 'A' && strtemp[i] <= 'Z')
					totalcnt[int(strtemp[i] - 'A')] += icnt;
			}
			strtemp.clear();
		}

		else if (ctemp == '-')
		{
			char cnext;
			char cend;
			cin >> cnext;
			cend = strtemp[strtemp.length() - 1];
			cend += 1;
			for (; cend <= cnext; cend += 1)
			{
				strtemp += cend;
			}
		}
		else
			strtemp += ctemp;
	}

	if (strtemp.length())
	{
		for (i = 0; i < strtemp.length(); i++)
		{
			if (strtemp[i] >= 'a' && strtemp[i] <= 'z')
				totalcnt[int(strtemp[i] - 'a')] += 1;
			else if (strtemp[i] >= 'A' && strtemp[i] <= 'Z')
				totalcnt[int(strtemp[i] - 'A')] += 1;
		}
	}

	ctemp = 'a';
	icnt = totalcnt[0];
	for (i = 1; i < 26; i++)
	{
		if (totalcnt[i] > icnt)
		{
			icnt = totalcnt[i];
			ctemp = 'a' + i;
		}
	}
	cout << ctemp << icnt;
	return 0;
}