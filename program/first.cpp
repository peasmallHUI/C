#include <iostream>
#include <ctime>
int main()
{
    using namespace std;
    float secs;
    clock_t delay, start;
    cout << "THIS PROGARM FOR TIME DELAY!"<< endl
         << "Please input delay time in seconds:";
    cin  >> secs;
    delay = secs * CLOCKS_PER_SEC;
    start = clock();
    while (clock() - start < delay);
    cout << "Done \a\n";
    return 0;
}
