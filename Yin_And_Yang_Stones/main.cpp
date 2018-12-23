#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int w_count = 0;
    int b_count = 0;

    for (auto it : s) {
        if (it == 'W') {
            w_count++;
        } else {
            b_count++;
        }
    }

    if (w_count == b_count) {
        cout << 1;
    } else {
        cout << 0;
    }

    return 0;
}
