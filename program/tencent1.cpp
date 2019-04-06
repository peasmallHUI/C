#include <iostream>

using namespace std;

int main()
{
    int n;
    int flag[501] = {0};
    int temp;
    int sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        flag[temp]++;
    }
    for (int i = 1; i < 500; i++)
    {
        sum +=flag[i]/i;
        if (flag[i]%i)
            flag[0] = 1;
    }
    if (flag[0])
        sum = -1;
    cout << sum << endl;
    return 0;
}