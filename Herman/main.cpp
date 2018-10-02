#include <iostream>
#include <iomanip>

double pi = 3.1415926535897;

using namespace std;

int main()
{
    int r;
    cin >> r;

    cout << fixed;
    cout << setprecision(6) << pi * r * r << endl;
    cout << r * r * 2.0;

    return 0;
}
