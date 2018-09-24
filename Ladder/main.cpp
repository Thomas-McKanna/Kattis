#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int h;
    double v;

    cin >> h >> v;

    v = M_PI * (v / 180);

    double x = h / sin(v);
    x = ceil(x);

    cout << x;

    return 0;
}
