#include <iostream>

using namespace std;

int main()
{
    int h, t;

    cin >> h >> t;
    int count;
    while (t != 0 || h != 0) {
        // check for impossibility
        if (t == 0 && h % 2 == 1) {
            cout << -1 << endl;
        } else {
            count = 0;
            while (h != 0 || t != 0) {
                if ((t >= 2 && h % 2 == 1) || t >= 4) {
                    t -= 2;
                    h += 1;
                } else if (h >= 2) {
                    h -= 2;
                } else {
                    t += 1;
                }
                count++;
            }
            cout << count << endl;
        }
        cin >> h >> t;
    }

    return 0;
}
