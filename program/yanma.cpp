#include <iostream>
int main ()
{
        int x = 0x87654321;
        //std::cin >> x;
        std::cout << std::hex << x << std::endl;
        std::cout << std::hex << (x & 0xFF) << std::endl;
        std::cout << std::hex << ((~0 - 0xFF)^x) << std::endl;
        std::cout << std::hex << (x | 0xFF) << std::endl;
        return 0;
}