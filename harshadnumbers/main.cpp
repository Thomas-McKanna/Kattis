#include <iostream>
#include <climits>

using namespace std;

bool is_harshad_number(int n) {
    int temp = n;
    int sum = 0;
    while (temp != 0) {
        sum += temp % 10;
        temp /= 10;
    }

    return n % sum == 0;
}

int main()
{
    int n;
    cin >> n;

    for (int i = n; i < INT_MAX; i++) {
        if (is_harshad_number(i)) {
            cout << i;
            break;
        }
    }

    return 0;
}
