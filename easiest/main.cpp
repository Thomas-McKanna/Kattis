#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int sum_n, sum_np, temp;
    while (n != 0) {
        temp = n;
        sum_n = 0;
        while (temp != 0) {
            sum_n += temp % 10;
            temp /= 10;
        }

        for (int p = 11; p <= 100000; p++) {
            temp = p*n;
            sum_np = 0;
            while (temp != 0) {
                sum_np += temp % 10;
                temp /= 10;
            }
            if (sum_n == sum_np) {
                cout << p;
                break;
            }
        }

        cin >> n;
        if (n != 0) {
            cout << endl;
        }
    }
    return 0;
}
