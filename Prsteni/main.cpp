#include <iostream>

using namespace std;

int gcd(int a, int b) {
    int temp;
    while (a % b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }

    return b;
}

int main()
{
    int n;
    cin >> n;

    int first;
    cin >> first;

    int in, a;
    for (int i = 0; i < n - 1; i++) {
        cin >> in;
        a = gcd(first, in);
        cout << first / a << "/" << in / a << endl;
    }

    return 0;
}
