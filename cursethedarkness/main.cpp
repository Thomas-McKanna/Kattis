#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int m;
    cin >> m;

    while (m--) {
        double bx, by;
        cin >> bx >> by;
        int n;
        cin >> n;
        bool found = false;
        while (n--) {
            double x, y;
            cin >> x >> y;
            double p = abs(bx - x), q = abs(by - y);
            if (p * p + q * q <= 64.0f) {
                found = true;
                break;
            }
        }
        if (found) {
            cout << "light a candle" << endl;
        }
        else {
            cout << "curse the darkness" << endl;
        }
    }

    return 0;
}