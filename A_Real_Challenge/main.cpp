#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    long a;
    cin >> a;

    cout << fixed << setprecision(7) << 4 * sqrt(a);

    return 0;
}
