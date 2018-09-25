#include <iostream>

using namespace std;

void rec_print(int n, bool flag) {
    string s1, s2;
    if (n < 1) {
        return;
    } else if (n == 1) {
        cin >> s1;
        cout << s1 << endl;
    } else {
        cin >> s1 >> s2;
        cout << s1 << endl;
        if (flag) {
            rec_print(n - 2, false);
            cout << s2;
        } else {
            rec_print(n - 2, false);
            cout << s2 << endl;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    int counter = 1;
    while (n != 0) {
        cout << "SET " << counter++ << endl;
        rec_print(n, true);
        cin >> n;
        if (n != 0) {
            cout << endl;
        }
    }

    return 0;
}
