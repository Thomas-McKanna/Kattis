#include <iostream>

using namespace std;

int main()
{
    int x, y;

    cin >> x >> y;
    int count = 0;

    bool no_newline = true;

    while (x != 0 || y != 0 && count < 15) {
        if (no_newline) {
            no_newline = false;
        } else {
            cout << endl;
        }
        if (x + y == 13) {
            cout << "Never speak again.";
        } else if (x > y) {
            cout << "To the convention.";
        } else if (x < y) {
            cout << "Left beehind.";
        } else if (x == y) {
            cout << "Undecided.";
        }

        cin >> x >> y;
        count++;
    }

    return 0;
}
