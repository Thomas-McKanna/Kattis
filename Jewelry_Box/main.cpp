#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int t;
    cin >> t;

    cout << fixed << setprecision(11);
    int x, y;
    double h;
    for (int i = 0; i < t; i++) {
        cin >> x >> y;
        h = (4*(x + y) - sqrt(16*pow(x + y, 2) - 48*x*y))/24;
        cout << 4*pow(h, 3) - 2*pow(h, 2)*(x + y) + h*x*y;
        cout << endl;
    }

    return 0;
}
