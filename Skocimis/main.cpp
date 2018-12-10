#include <iostream>
#include <cmath>

using namespace std;

bool next(bool b) {
    if (b) {
        return false;
    } else {
        return true;
    }
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    bool o = true;

    int count = 0;
    int iter = 0;

    int pos[3] = {a, b, c};

    while (abs(pos[(iter + 1) % 3] - pos[(iter + 2) % 3]) > 1) {
        count++;
        if (o) {
            pos[iter % 3] = pos[(iter + 1) % 3] + 1;
        } else {
            pos[iter % 3] = pos[(iter + 1) % 3] - 1;
        }
        o = next(o);
        iter++;
    }

    int ans1 = count;

    o = true;

    count = 0;
    iter = 2;

    pos[0] = a;
    pos[1] = b;
    pos[2] = c;

    while (abs(pos[(iter + 1) % 3] - pos[(iter + 2) % 3]) > 1) {
        count++;
        if (o) {
            pos[iter % 3] = pos[(iter + 1) % 3] + 1;
        } else {
            pos[iter % 3] = pos[(iter + 1) % 3] - 1;
        }
        o = next(o);
        iter++;
    }

    int ans2 = count;

    if (ans1 > ans2) {
        cout << ans1;
    } else {
        cout << ans2;
    }

    return 0;
}
