#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int cal;
    for (int i = 0; i < t; i++) {
        cin >> cal;
        cout << ceil(cal / 400.0) << endl;
    }

    return 0;
}
