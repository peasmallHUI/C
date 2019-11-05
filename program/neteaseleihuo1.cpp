#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int* rect_wh = new int[2 * N];
	int* rect_sum = new int[N];
	int i = 0;
	while (i<N)
	{
		int w, h;
		cin >> w;
		cin >> h;
		rect_wh[i * 2] = w;
		rect_wh[i * 2 + 1] = h;
		rect_sum[i] = w * h;
		i++;
	}


	for (int end = N-1; end > 0; end--)
	{
		for (i = 0; i < end; i++)
		{
			if (rect_sum[i] > rect_sum[i + 1])
			{
				int temp = rect_sum[i];
				rect_sum[i] = rect_sum[i + 1];
				rect_sum[i + 1] = temp;

				temp = rect_wh[i * 2];
				rect_wh[i * 2] = rect_wh[i * 2 + 2];
				rect_wh[i * 2 + 2] = temp;

				temp = rect_wh[i * 2 + 1];
				rect_wh[i * 2 + 1] = rect_wh[i * 2 + 3];
				rect_wh[i * 2 + 3] = temp;
			}
			else if (rect_sum[i] == rect_sum[i + 1])
			{
				float w1 = rect_wh[i * 2];
				float h1 = rect_wh[i * 2 + 1];
				float w2 = rect_wh[i * 2 + 2];
				float h2 = rect_wh[i * 2 + 3];
				float wh1 = w1 / h1 < h1 / w1 ? w1 / h1 : h1 / w1;
				float wh2 = w2 / h2 < h2 / w2 ? w2 / h2 : h2 / w2;

				if (wh1 < wh2)
				{
					int temp = rect_sum[i];
					rect_sum[i] = rect_sum[i + 1];
					rect_sum[i + 1] = temp;

					temp = rect_wh[i * 2];
					rect_wh[i * 2] = rect_wh[i * 2 + 2];
					rect_wh[i * 2 + 2] = temp;

					temp = rect_wh[i * 2 + 1];
					rect_wh[i * 2 + 1] = rect_wh[i * 2 + 3];
					rect_wh[i * 2 + 3] = temp;
				}
				else if (wh1 == wh2 && w1 >= w2)
				{
					int temp = rect_sum[i];
					rect_sum[i] = rect_sum[i + 1];
					rect_sum[i + 1] = temp;

					temp = rect_wh[i * 2];
					rect_wh[i * 2] = rect_wh[i * 2 + 2];
					rect_wh[i * 2 + 2] = temp;

					temp = rect_wh[i * 2 + 1];
					rect_wh[i * 2 + 1] = rect_wh[i * 2 + 3];
					rect_wh[i * 2 + 3] = temp;
				}
			}

		}
	}

	for (i = 0; i < 2 * N; i++)
	{
		cout << rect_wh[i] << " ";
	}

	return 0;
}

