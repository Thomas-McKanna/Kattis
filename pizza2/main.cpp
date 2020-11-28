#include <iostream>
#include <cmath>
#include <iomanip>

double PI = atan(1)*4;

using namespace std;

int main()
{
    int r, c;
    cin >> r >> c;

    double whole = PI * r * r;
    double cheese = PI * (r - c) * (r - c);

    cout << fixed << setprecision(6) << (cheese / whole) * 100;

    return 0;
}
