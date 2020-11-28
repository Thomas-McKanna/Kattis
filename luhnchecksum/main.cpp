#include <iostream>

using namespace std;

char mask = 48;

int main()
{
    int t;
    cin >> t;

    string n;
    int m, s;
    bool toggle;

    for (int i = 0; i < t; i++) {
        s = 0;
        toggle = false;
        cin >> n;
        for (auto j = n.rbegin(); j != n.rend(); j++) {
            m = *j ^ mask;
            if (toggle) {
                if (m * 2 > 9) {
                    m = m * 2 - 9;
                } else {
                    m *= 2;
                }
            }
            s += m;
            if (toggle) {
                toggle = false;
            } else {
                toggle = true;
            }
        }
        if (s % 10 == 0) {
            cout << "PASS" << endl;
        } else {
            cout << "FAIL" << endl;
        }

    }

    return 0;
}
