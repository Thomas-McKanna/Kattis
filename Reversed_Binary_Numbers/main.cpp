#include <iostream>
#include <cmath>
#include <stack>

using namespace std;

int main()
{
    int n;
    cin >> n;

    stack<int> bits;

    while (n != 0) {
        bits.push(n % 2);
        n = n / 2;
    }

    int mult = 1;
    int sum = 0;
    int i;
    while (!bits.empty()) {
        i = bits.top();
        bits.pop();
        if (i == 1) {
            sum += mult;
        }
        mult *= 2;
    }

    cout << sum;

    return 0;
}
