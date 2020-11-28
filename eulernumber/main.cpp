#include <iostream>
#include <iomanip>
#include <vector>
#include <limits.h>

using namespace std;


unsigned long factorial(int n) {
    if (n <= 0) {
        return 1;
    }

    unsigned long sum = 1;
    for (; n > 0; n--) {
        sum *= n;
    }

    return sum;
}

int main()
{
    int n;
    cin >> n;

    double sum = 0;
    for (int i = 0; i <= n && i <= 16; i++) {
        sum += 1.0 / factorial(i);
    }

    cout << fixed << setprecision(15) << sum << endl;
    return 0;
}
