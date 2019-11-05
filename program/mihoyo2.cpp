#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int ret = 0;
    int times = 0;
    int R, C;
    cin >> R >> C;
    char * pChess = new char(R*C);
    memset(pChess, 0, R*C);
    int ir1, ic1;
    int ir2, ic2;
    char ctemp;
    for (int cnt=0; cnt<R*C; cnt++)
    {
        cin >> ctemp;
        pChess[cnt] = ctemp;
    }
    cin >> ir1 >> ic1 >> ir2 >> ic2;
    ctemp = pChess[ir1*R + ic1];
    pChess[ir1*R + ic1] = pChess[ir2*R + ic2];
    pChess[ir2*R + ic2] = ctemp;

    int irtemp, ictemp;

    irtemp = ir1 - 1;
    ictemp = ic1;
    while ( (irtemp<R && irtemp>=0) && (ictemp<C && ictemp>=0) && pChess[ir1*R + ic1] == pChess[irtemp*R + ictemp])
    {
        irtemp -= 1;
    }
    if (ir1 - irtemp >=3)
    {
        ret += ir1 - irtemp;
        times += 1;
    }
        

    irtemp = ir1 + 1;
    ictemp = ic1;
    while ( (irtemp<R && irtemp>=0) && (ictemp<C && ictemp>=0) && pChess[ir1*R + ic1] == pChess[irtemp*R + ictemp])
    {
        irtemp += 1;
    }
    if (irtemp - ir1 >=3)
    {
        ret += irtemp - ir1;
        times += 1;
    }
        

    irtemp = ir1;
    ictemp = ic1 - 1;
    while ( (irtemp<R && irtemp>=0) && (ictemp<C && ictemp>=0) && pChess[ir1*R + ic1] == pChess[irtemp*R + ictemp])
    {
        ictemp -= 1;
    }
    if (ic1 - ictemp >=3)
    {
        ret += ic1 - ictemp;
        times += 1;
    }
        

    irtemp = ir1;
    ictemp = ic1 + 1;
    while ( (irtemp<R && irtemp>=0) && (ictemp<C && ictemp>=0) && pChess[ir1*R + ic1] == pChess[irtemp*R + ictemp])
    {
        ictemp += 1;
    }
    if (ictemp - ic1 >=3)
    {
        ret += ictemp - ic1;
        times += 1;
    }
        

    irtemp = ir2 - 1;
    ictemp = ic2;
    while ( (irtemp<R && irtemp>=0) && (ictemp<C && ictemp>=0) && pChess[ir2*R + ic2] == pChess[irtemp*R + ictemp])
    {
        irtemp -= 1;
    }
    if (ir2 - irtemp >=3)
    {
        ret += ir2 - irtemp;
        times += 1;
    }
        

    irtemp = ir2 + 1;
    ictemp = ic2;
    while ( (irtemp<R && irtemp>=0) && (ictemp<C && ictemp>=0) && pChess[ir2*R + ic2] == pChess[irtemp*R + ictemp])
    {
        irtemp += 1;
    }
    if (irtemp - ir2 >=3)
    {
        ret += irtemp - ir2;
        times += 1;
    }
        

    irtemp = ir2;
    ictemp = ic2 - 1;
    while ( (irtemp<R && irtemp>=0) && (ictemp<C && ictemp>=0) && pChess[ir2*R + ic2] == pChess[irtemp*R + ictemp])
    {
        ictemp -= 1;
    }
    if (ic2 - ictemp >=3)
    {
        ret += ic2 - ictemp;
        times += 1;
    }
        

    irtemp = ir2;
    ictemp = ic2 + 1;
    while ( (irtemp<R && irtemp>=0) && (ictemp<C && ictemp>=0) && pChess[ir2*R + ic2] == pChess[irtemp*R + ictemp])
    {
        ictemp += 1;
    }
    if (ictemp - ic2 >=3)
    {
        ret += ictemp - ic2;
        times += 1;
    }
        
    if (times>0)
        ret -= times -1;
    cout << ret;
    
    return 0;
}