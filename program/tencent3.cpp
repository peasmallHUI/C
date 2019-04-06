#include <iostream>

using namespace std;

int main()
{
    int N;
    int v;
    int *tPtr;
    int sum = 0;
    int tick;
    int temp;
    int twait;
    cin >> N;
    tPtr = new int[N];

    for (int i = 0; i < N; i++)
        cin >> tPtr[i];

    cin >> v;
    tick = 150 / v;
    sum += tick;
    for (int i = 0; i < N; i++)
    {
        
        temp = sum / tPtr[i];

        if(temp % 2)
        {
            twait = ((temp+1)*tPtr[i] - sum);
            sum += (tick + twait);
        }
        else 
        {
            sum += tick;
        }
    }
    cout << sum << endl;
    delete[] tPtr;
    return 0;
}