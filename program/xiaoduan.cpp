#include <iostream>
int main()
{
    union xiaoduan
    {
        int a;
        char b;
    } x;
    x.a = 0x01234567;
    std::cout << std::hex << int(x.b);
    return 0;
}