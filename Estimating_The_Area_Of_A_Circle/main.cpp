#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double PI = 4 * atan(1);

int main()
{
    double r;
    double m, c;

    cin >> r >> m >> c;
    cout << fixed << setprecision(6);
    while (r != 0 || m != 0 || c != 0) {
        cout << PI * r * r << " " << (2 * r) * (2 * r) * (c / m) << endl;
        cin >> r >> m >> c;
    }

    return 0;
}
