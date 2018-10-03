#include <iostream>

using namespace std;

int main()
{
    int x, y, z;
    cin >> x >> y >> z;

    if (x == y + z) {
        cout << x << "=" << y << "+" << z;
    } else if (x == y - z) {
        cout << x << "=" << y << "-" << z;
    } else if (x == y * z) {
        cout << x << "=" << y << "*" << z;
    } else if (y % z == 0 && x == y / z) {
        cout << x << "=" << y << "/" << z;
    } else if (x + y == z) {
        cout << x << "+" << y << "=" << z;
    } else if (x - y == z) {
        cout << x << "-" << y << "=" << z;
    } else if (x * y == z) {
        cout << x << "*" << y << "=" << z;
    } else {
        cout << x << "/" << y << "=" << z;
    }

    return 0;
}
