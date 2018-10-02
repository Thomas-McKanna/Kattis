#include <iostream>

using namespace std;

int main()
{
    int a1, b1, a2, b2, c1, d1, c2, d2;
    cin >> a1 >> b1 >> a2 >> b2 >> c1 >> d1 >> c2 >> d2;

    double gunnar = ((a1 + b1) / 2.0) + ((a2 + b2) / 2.0);

    double emma = ((c1 + d1) / 2.0) + ((c2 + d2) / 2.0);

    if (gunnar > emma) {
        cout << "Gunnar";
    } else if (gunnar < emma) {
        cout << "Emma";
    } else {
        cout << "Tie";
    }

    return 0;
}
