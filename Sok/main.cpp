#include <iostream>
#include <iomanip>
#include <cmath>
#include <map>
#include <utility>

using namespace std;

#define ZERO -0.000000001

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    int i, j, k;
    cin >> i >> j >> k;

    map<double, int> m;
    double t1 = double (a) / i;
    double t2 = double (b) / j;
    double t3 = double (c) / k;

    if (a - (t3 * i) >= ZERO && b - (t3 * j) >= ZERO && c - (t3 * k) >= ZERO) {
        m[a - (t3 * i) + b - (t3 * j) + c - (t3 * k)] = 3;
    }

    if (a - (t2 * i) >= ZERO && b - (t2 * j) >= ZERO && c - (t2 * k) >= ZERO) {
        m[a - (t2 * i) + b - (t2 * j) + c - (t2 * k)] = 2;
    }

    if (a - (t1 * i) >= ZERO && b - (t1 * j) >= ZERO && c - (t1 * k) >= ZERO) {
        m[a - (t1 * i) + b - (t1 * j) + c - (t1 * k)] = 1;
    }

    auto ans = *(m.begin());

    cout << fixed << setprecision(6);
    if (ans.second == 1) {
        cout << abs(a - (t1 * i)) << " " << abs(b - (t1 * j)) << " " << abs(c - (t1 * k));
    } else if (ans.second == 2) {
        cout << abs(a - (t2 * i)) << " " << abs(b - (t2 * j)) << " " << abs(c - (t2 * k));
    } else {
        cout << abs(a - (t3 * i)) << " " << abs(b - (t3 * j)) << " " << abs(c - (t3 * k));
    }

    return 0;
}
