#include <iostream>

using namespace std;

int main()
{
    int a[6];

    for (int i = 0; i < 6; i++) {
        cin >> a[i];
    }

    a[0] = 1 - a[0];
    a[1] = 1 - a[1];
    a[2] = 2 - a[2];
    a[3] = 2 - a[3];
    a[4] = 2 - a[4];
    a[5] = 8 - a[5];

    for (int i = 0; i < 6; i++) {
        if (i < 5) {
            cout << a[i] << " ";
        } else {
            cout << a[i];
        }
    }

    return 0;
}
