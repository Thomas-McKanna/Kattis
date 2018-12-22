#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double PI = 4 * atan(1);

int main()
{
    int a, b, s, m, n;
    cin >> a >> b >> s >> m >> n;

    int x_dist, y_dist;
    cout << fixed;
    while (a != 0 || b != 0 || s != 0 || m != 0 || n != 0) {
        x_dist = a * m;
        y_dist = b * n;

        cout << setprecision(2) << atan(y_dist / (double) x_dist) * (180 / PI);
        cout << " ";
        cout << setprecision(2) << sqrt(pow(x_dist, 2) + pow(y_dist, 2)) / s << endl;

        cin >> a >> b >> s >> m >> n;
    }

    return 0;
}
