#include <iostream>

bool is_little_endian();
int main()
{
    
    std::cout << is_little_endian;
    return 0;
}

bool is_little_endian()
{
    union xiaoduan
    {
        int a;
        char b;
    } x;
    x.a = 0x01234567;
    return 0x01 == x.b; 
}