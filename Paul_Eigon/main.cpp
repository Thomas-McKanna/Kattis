#include <iostream>

using namespace std;

int main()
{
    int n, p, q;
    cin >> n >> p >> q;

    int quotient = (p + q) / n;

    if (quotient % 2 == 0) {
        cout << "paul";
    } else {
        cout << "opponent";
    }

    return 0;
}
