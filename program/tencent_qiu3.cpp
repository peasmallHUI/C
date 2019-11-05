#include <iostream>
#include <cmath>
using namespace std;
struct tri
{
    float x;
    float y;
    float z;
};

int main()
{
    int n;
    cin >> n;
    int x0,y0,x1,y1,x2,y2;
    struct tri* triangel = new tri[n];
    int i = 0;
    int ret = 0;
    int t = 0;
    while (t < n)
    {
        cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;
        (triangel + i)->x = pow((x0 - x1),2) + pow((y0 - y1), 2);
        (triangel + i)->y = pow((x0 - x2),2) + pow((y0 - y2), 2);
        (triangel + i)->z = pow((x2 - x1),2) + pow((y2 - y1), 2);
        if ((triangel + i)->x > (triangel + i)->y)
        {
            float tmp = (triangel + i)->x;
            (triangel + i)->x = (triangel + i)->y;
            (triangel + i)->y = tmp;
        }

        if ((triangel + i)->x > (triangel + i)->z)
        {
            float tmp = (triangel + i)->x;
            (triangel + i)->x = (triangel + i)->z;
            (triangel + i)->z = tmp;
        }

        if ((triangel + i)->z > (triangel + i)->y)
        {
            float tmp = (triangel + i)->z;
            (triangel + i)->z = (triangel + i)->y;
            (triangel + i)->y = tmp;
        }

        t += 1;
        i += 1;
    }

    for (int j=0; j<n; j++)
    {
        for (int k=j+1; k<n; k++)
        {
            if ( ((triangel + j)->x == (triangel + k)->x) &&((triangel + j)->y == (triangel + k)->y) && ((triangel + j)->z == (triangel + k)->z))
                ret += 1;
        }
    }
    
    cout << ret;
    delete [] triangel;
    return 0;
}