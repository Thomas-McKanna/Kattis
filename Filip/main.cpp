#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    int temp_a, temp_b, a_rev, b_rev;
    a_rev = 0;
    b_rev = 0;
    for (int i = 0; i < 3; i++) {
        temp_a = a % 10;
        temp_b = b % 10;
        a_rev = a_rev*10 + temp_a;
        b_rev = b_rev*10 + temp_b;
        a /= 10;
        b /= 10;
    }

    cout << max(a_rev, b_rev);

    return 0;
}
