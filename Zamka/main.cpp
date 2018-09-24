#include <iostream>

using namespace std;

int main()
{
    int L, d, x;

    cin >> L >> d >> x;

    // Finding N
    int temp;
    int sum;
    for (int i = L; i <= d; i++) {
        sum = 0;
        temp = i;
        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }
        if (sum == x) {
            cout << i << endl;
            break;
        }
    }

    // Finding M
    for (int i = d; i >= L; i--) {
        sum = 0;
        temp = i;
        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }
        if (sum == x) {
            cout << i;
            break;
        }
    }

    return 0;
}
