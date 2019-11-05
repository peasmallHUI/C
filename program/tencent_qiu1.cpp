#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    int n,m,i;
    int ret = 0;
    cin >> n >> m;
    int* cnt = new int[m];
    memset(cnt, 0, sizeof(int)*m);
    while (cin >> i)
    {
        *(cnt+i-1) += 1;
    }

    for (int i=0; i<m; i++)
    {
        if(*(cnt+i-1)/3)
        {
            ret += *(cnt+i-1)/3;
            *(cnt+i-1) = *(cnt+i-1)%3;
        }

    }

    for (int i=0; i<m; i++)
    {
        while ( (*(cnt+i-1) > 0) && (*(cnt+i) > 0) &&(*(cnt+i+1) > 0) )
        {
            ret += 1;
            *(cnt+i-1) -= 1;
            *(cnt+i) -= 1;
            *(cnt+i+1) -= 1;
        }
    }

    cout << ret;
    return 0;
}