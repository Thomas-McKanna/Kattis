#include <iostream>

using namespace std;

int main()
{
    int l, r;

    cin >> l >> r;

    if (l > r) {
        cout << "Odd " << 2 * l;
    } else if (r > l) {
        cout << "Odd " << 2 * r;
    } else {
        if (l == 0) {
            cout << "Not a moose";
        } else {
            cout << "Even " << 2 * l;
        }
    }

    return 0;
}
