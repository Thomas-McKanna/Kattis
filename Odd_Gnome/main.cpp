#include <iostream>

using namespace std;

int main()
{
    int n, g, q, prev;
    bool ans_given;
    cin >> n;

    for (int i = 0; i < n; i++) {
        ans_given = false;
        cin >> g >> prev;
        for (int j = 1; j < g; j++) {
            cin >> q;
            if (!ans_given && q != prev + 1) {
                cout << j + 1 << endl;
                ans_given = true;
            }
            prev = q;
        }
    }

    return 0;
}
