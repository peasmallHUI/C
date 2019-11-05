#include <iostream>
using namespace std;
int main()
{
	int N;
	float Fmin = 1.0;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= i; j++)
		{
			
			if (i == 1 || j == 1)
				cnt++;
			else
			{
				int x = i;
				int y = j;
				int temp;
				while (1)
				{
					temp = x % y;
					if (temp == 0)
						break;
					x = y;
					y = temp;
				}
				if (y == 1)
					cnt++;
			}
		}
		float ftemp = float(cnt) / float(i);

		if (ftemp < Fmin)
			Fmin = ftemp;
	}

	printf("%1.6f", Fmin);
	return 0;
}