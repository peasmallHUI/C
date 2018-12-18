#include  <iostream>
#include  <fstream>
int main ()
{
    using namespace std;

    char automobile[50];
    int year;
    double a_price;
    double d_price;
    ofstream outFile;
    outFile.open("test.txt");

    cout << "1";
    cin.getline(automobile,50) >> year;
    cin >> a_price;
    cout << fixed;
    cout.precision(2);
    cout.setf(ios_base::showpoint);
    cout << automobile << endl;
    outFile << year << endl;

    outFile.close();
    return 0;
}
