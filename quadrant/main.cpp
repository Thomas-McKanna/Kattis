#include <iostream>

using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;

    if (x > 0) {
        if (y > 0) {
            // Q1
            cout << 1;
        } else {
            // Q4
            cout << 4;
        }
    } else {
        if (y > 0) {
            // Q2
            cout << 2;
        } else {
            // Q3
            cout << 3;
        }
    }

    return 0;
}
