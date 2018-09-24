#include <iostream>

using namespace std;

int main()
{
    int x, n, p;

    cin >> x >> n;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> p;
        sum += x - p;
    }

    sum += x;

    cout << sum;

    return 0;
}
