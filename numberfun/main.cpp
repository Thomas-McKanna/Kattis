#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int a, b, c;
    bool flag;
    for (int i = 0; i < n; i++) {
        flag = false;
        cin >> a >> b >> c;

        if (a + b == c) {
            flag = true;
        }
        else if (a * b == c) {
            flag = true;
        }
        else if (abs(a - b) == abs(c)) {
            flag = true;
        }
        else if (a > b && a % b == 0 && a / b == c) {
            flag = true;
        }
        else if (a >= b && a % b == 0 && a / b == c) {
            flag = true;
        }
        else if (b >= a && b % a == 0 && b / a == c) {
            flag = true;
        }

        if (flag) {
            cout << "Possible";
        } else {
            cout << "Impossible";
        }

        if (i != n - 1) {
            cout << endl;
        }
    }

    return 0;
}
