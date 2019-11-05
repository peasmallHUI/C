#include <iostream>
#include <cstring>

using namespace std;

int main1()
{
	int T;
	cin >> T;
	int x, y;
	char z[62];
	while (cin >> x >> y)
	{
		cin.getline(z, 62);
		int len = strlen(z);
		int frontNum = 0;
		int backNum = 0;
		int frontFlag = 1;
		int backFlag = len - 1;
		unsigned long flag = 1;
		for (; frontFlag <= backFlag;)
		{

			if (frontNum < backNum)
			{
				if (z[frontFlag] >= '0' && z[frontFlag] <= '9')
				{
					frontNum = frontNum * x + z[frontFlag] - '0';
				}
				else if (z[frontFlag] >= 'A' && z[frontFlag] <= 'F')
				{
					frontNum = frontNum * x + z[frontFlag] - 'A' + 10;
				}
				frontFlag += 1;
			}
			else
			{
				if (z[backFlag] >= '0' && z[backFlag] <= '9')
				{
					backNum = backNum + (z[backFlag] - '0') * flag;
				}
				else if (z[backFlag] >= 'A' && z[backFlag] <= 'F')
				{
					backNum = backNum + (z[backFlag] - 'A' + 10) * flag;
				}

				flag *= y;
				backFlag -= 1;
			}
		}
		cout << frontNum << endl;
	}
	return 0;
}