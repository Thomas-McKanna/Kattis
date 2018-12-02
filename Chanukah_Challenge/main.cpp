#include <iostream>

using namespace std;

int sum(int n) {
    return (1 + n) * (n / 2.0);
}

int main()
{
    int p;
    cin >> p;

    int k;
    for (int i = 0; i < p; i++) {
        cin >> k >> k;
        cout << i + 1 << " " << sum(k) + k << endl;
    }

    return 0;
}
