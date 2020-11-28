#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double PI = 4*atan(1);

int main()
{
    double r, x, y, d, h, c, a, inter;
    cout << fixed << setprecision(6);
    while (cin >> r >> x >> y) {
        d = sqrt(pow(x, 2) + pow(y, 2));
        if (d > r) {
            cout << "miss" << endl;
        } else {
            // See https://en.wikipedia.org/wiki/Circular_segment
            h = r - d;
            c = sqrt(8*h*(r - h/2));
            inter = c / (2*r);
            a = pow(r, 2)*(asin(inter) - inter*sqrt(1 - pow(inter, 2)));
            cout << PI*pow(r, 2) - a << " " << a << endl;
        }
    }

    return 0;
}
