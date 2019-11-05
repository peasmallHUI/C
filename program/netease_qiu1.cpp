#include <iostream>

using namespace std;
int main3()
{
	int n;
	float income;
	float tax = 0;
	cin >> n;
	while (cin >> income)
	{
		
		income -= 5000;
		if (income <= 0)
		{
			tax = 0;
		}
		else if (income <= 3000)
		{
			tax = income * 0.03;
		}
		else if (income <= 12000)
		{
			tax = 90 + (income - 3000)*0.1;
		}
		else if (income <= 25000)
		{
			tax = 90 + 900 + (income - 12000)*0.2;
		}
		else if (income <= 35000)
		{
			tax = 90 + 900 + 2600 + (income - 25000)*0.25;
		}
		else if (income <= 55000)
		{
			tax = 90 + 900 + 2600 + 2500 + (income - 35000)*0.30;
		}
		else if (income <= 80000)
		{
			tax = 90 + 900 + 2600 + 2500 + 6000 + (income - 55000)*0.35;
		}
		else
		{
			tax = 90 + 900 + 2600 + 2500 + 6000 + (income - 80000)*0.45;
		}
		cout << int(tax + 0.5) << endl;
	}
	return 0;
}