#include <iostream>

using namespace std;

int main()
{
    int p;
    cin >> p;

    int k, n;
    for (int i = 0; i < p; i++) {
        cin >> k >> n;
        cout << k << " ";
        cout << int(n*(1 + n)/2.0) << " ";
        cout << n*((1 + (n * 2 - 1))/2) << " ";
        cout << n*((2 + (n * 2))/2);
        if (i != p - 1) {
            cout << endl;
        }
    }

    return 0;
}
