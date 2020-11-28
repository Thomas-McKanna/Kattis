#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;

    string s;
    int side;
    for (int i = 0; i < t; i++) {
        cin >> s;
        side = int(sqrt(s.length()));

        for (int j = side - 1; j >= 0; j--) {
            for (int k = 0; k < side; k++) {
                cout << s[j + side*k];
            }
        }
        cout << endl;
    }

    return 0;
}
