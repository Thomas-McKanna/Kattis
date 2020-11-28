#include <iostream>
#include <stack>

using namespace std;

enum DIRECTION {RIGHT, LEFT};

int main()
{
    int p;
    cin >> p;

    int n;
    unsigned int num, den;
    stack<DIRECTION> path;
    DIRECTION dir;
    for (int i = 0; i < p; i++) {
        cin >> n >> n;

        while (n > 1) {
            if (n % 2 == 0) {
                path.push(LEFT);
            } else {
                path.push(RIGHT);
            }
            n /= 2;
        }

        num = 1;
        den = 1;
        while (!path.empty()) {
            dir = path.top();
            path.pop();
            if (dir == LEFT) {
                den = num + den;
            } else {
                num = num + den;
            }
        }

        cout << i + 1 << " " << num << "/" << den << endl;
    }

    return 0;
}
