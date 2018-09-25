#include <iostream>

using namespace std;

int main()
{
    int x1, x2, x3, y1, y2, y3;

    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    int pos_x1, pos_x2, pos_y1, pos_y2;

    int x[2] = {0, 0};
    int y[2] = {0, 0};

    pos_x1 = x1;
    x[0]++;

    if (x2 == x1) {
        x[0]++;
    } else {
        pos_x2 = x2;
        x[1]++;
    }

    if (x3 == x1) {
        x[0]++;
    } else {
        pos_x2 = x3;
        x[1]++;
    }

    pos_y1 = y1;
    y[0]++;

    if (y2 == y1) {
        y[0]++;
    } else {
        pos_y2 = y2;
        y[1]++;
    }

    if (y3 == y1) {
        y[0]++;
    } else {
        pos_y2 = y3;
        y[1]++;
    }

    if (x[0] > x[1]) {
        cout << pos_x2;
    } else {
        cout << pos_x1;
    }

    cout << " ";

    if (y[0] > y[1]) {
        cout << pos_y2;
    } else {
        cout << pos_y1;
    }

    return 0;
}
