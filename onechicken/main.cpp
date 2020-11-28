#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    if (m - 1 > n) {
        cout << "Dr. Chaz will have " << m - n << " pieces of chicken left over!";
    } else if (m > n) {
        cout << "Dr. Chaz will have " << 1 << " piece of chicken left over!";
    } else if (n - 1 > m) {
        cout << "Dr. Chaz needs " << n - m << " more pieces of chicken!";
    } else {
        cout << "Dr. Chaz needs " << 1 << " more piece of chicken!";
    }

    return 0;
}
