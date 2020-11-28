#include <iostream>
#include <stack>

using namespace std;

const int LEFT = 0;
const int RIGHT = 1;

int main()
{
    int P, k, p, q;
    cin >> P;

    int pos;
    stack<int> dirs;
    for (int i = 0; i < P; i++) {
        cin >> k >> p;
        cin.ignore();
        cin >> q;

        while (p != 1 || q != 1) {
            if (p < q) {
                q -= p;
                dirs.push(LEFT);
            } else {
                p -=q;
                dirs.push(RIGHT);
            }
        }

        pos = 0;
        while (!dirs.empty()) {
            if (dirs.top() == LEFT) {
                pos = 2 * pos + 1;
            } else {
                pos = 2 * pos + 2;
            }
            dirs.pop();
        }

        cout << k << " " << pos + 1 << endl;
    }

    return 0;
}
