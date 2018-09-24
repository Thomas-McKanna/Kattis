#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int current;
    for (int i = 0; i < n; i++) {
        cin >> current;
        if (current % 2 == 0) {
            cout << current << " is even";
        } else {
            cout << current << " is odd";
        }
        if (i != n - 1) {
            cout << endl;
        }
    }

    return 0;
}
