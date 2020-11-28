#include <iostream>
#include <cmath>

using namespace std;

double x(double t) {

}

int main()
{
    int n;
    cin >> n;

    double v, theta, x, h1, h2;

    for (int i = 0; i < n; i++) {
        cin >> v >> theta >> x >> h1 >> h2;

        theta = atan(1)*4 * (theta / 180);

        double t = x / (v * cos(theta));

        double y = v * t * sin(theta) - (1.0/2.0)*9.81*t*t;

        if (y >= h1 + 1 && y <= h2 - 1) {
            cout << "Safe";
        } else {
            cout << "Not Safe";
        }
        if (i != n - 1) {
            cout << endl;
        }
    }

    return 0;
}
