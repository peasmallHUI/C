#include <iostream>

using namespace std;

struct workdata
{
	int deadline;
	int cost;
	struct workdata* next;
};

int main()
{
	int N;
	int ret;
	cin >> N;
	int i = 0;
	struct workdata* data = new struct workdata;
	struct workdata* data_temp = new struct workdata;
	data->next = data_temp;
	while (i < N-1)
	{
		cin >> data_temp->deadline >> data_temp->cost;
		data_temp->next = new struct workdata;
		data_temp = data_temp->next;
		i++;
	}
	cin >> data_temp->deadline >> data_temp->cost;
	data_temp->next = nullptr;

	int maxdeadline = 0;
	struct workdata* index = new struct workdata;

	for (data_temp = data; data_temp->next != nullptr; )
	{
		if (data_temp->next->deadline > maxdeadline)
		{
			maxdeadline = data_temp->next->deadline;
			index = data_temp;
		}

		data_temp = data_temp->next;
	}

	maxdeadline -= index->next->cost;
	index->next = index->next->next;

	while (true)
	{
		int max = 0;

		for (data_temp = data; data_temp->next != nullptr; )
		{
			if (data_temp->next->deadline > max)
			{
				max = data_temp->next->deadline;
				index = data_temp;
			}
			data_temp = data_temp->next;
		}

		if (maxdeadline >= index->next->cost)
		{
			max -= index->next->cost;
			index->next = index->next->next;
			maxdeadline = max;
		}
		else
		{
			ret = index->next->cost - maxdeadline;
			break;
		}

	}

	cout << ret;
	return 0;
}