#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int r, e, c;
    for (int i = 0; i < n; i++) {
        cin >> r >> e >> c;
        e = e - c;
        if (r > e) {
            cout << "do not advertise";
        } else if (r < e) {
            cout << "advertise";
        } else {
            cout << "does not matter";
        }
        if (i != n - 1) {
            cout << endl;
        }
    }

    return 0;
}
