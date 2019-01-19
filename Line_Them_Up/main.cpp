#include <iostream>

using namespace std;

enum ORDER {INCREASING, DECREASING, NEITHER};

int main()
{
    int n;
    cin >> n;

    ORDER o;
    string curr, prev;
    cin >> prev >> curr;

    if (prev < curr) {
        o = INCREASING;
    } else {
        o = DECREASING;
    }

    prev = curr;
    for (int i = 2; i < n; i++) {
        cin >> curr;
        if ((o == INCREASING && prev > curr)
            || (o == DECREASING && prev < curr)) {
            o = NEITHER;
        }

        if (o == NEITHER) {
            break;
        }
        prev = curr;
    }

    string ans;
    switch(o) {
        case INCREASING:
            ans = "INCREASING";
            break;
        case DECREASING:
            ans = "DECREASING";
            break;
        case NEITHER:
            ans = "NEITHER";
    }

    cout << ans;

    return 0;
}
