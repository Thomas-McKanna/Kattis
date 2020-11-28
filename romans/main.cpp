#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double x;
    cin >> x;

    cout << (int) round(x * 1000 * (5280.0 / 4854));

    return 0;
}
