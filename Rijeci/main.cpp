#include <iostream>

using namespace std;

int main()
{
    int k;
    cin >> k;

    long fibo[k - 1];

    int s1 = 0;
    int s2 = 1;
    for (int i = 0; i < k - 1; i++) {
        fibo[i] = s1 + s2;
        s1 = s2;
        s2 = fibo[i];
    }

    if (k == 1) {
        cout << 0 << " " << 1;
    } else if (k == 2) {
        cout << fibo[0] << " " << fibo[0];
    } else {
        cout << fibo[k - 3] << " " << fibo[k - 2];
    }

    return 0;
}
