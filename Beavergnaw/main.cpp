#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double pi = atan(1)*4;

int main()
{
    int d, v;
    cin >> d >> v;

    cout << fixed << setprecision(9);
    while (d != 0 && v != 0) {
        cout << pow(pow(d, 3) - 6 * v / pi, 1.0/3.0) << endl;

        cin >> d >> v;
    }

    return 0;
}
