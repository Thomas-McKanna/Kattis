#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double x1, y1, x2, y2, p;

    cin >> x1 >> y1 >> x2 >> y2 >> p;

    cout << fixed << setprecision(6);

    while (x1 != 0) {
        cout << pow(pow(abs(x1 - x2), p) + pow(abs(y1 - y2), p), 1.0 / p) << endl;
        cin >> x1 >> y1 >> x2 >> y2 >> p;
    }

    return 0;
}
