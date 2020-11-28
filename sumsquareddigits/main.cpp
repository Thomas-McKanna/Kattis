#include <iostream>
#include <stack>

using namespace std;

stack<int> base10_to(int b, int n) {
    stack<int> s;

    while (n != 0) {
        s.push(n % b);
        n /= b;
    }
    return s;
}

int ssd(stack<int> s) {
    int sum = 0;
    int temp;
    while (!s.empty()) {
        temp = s.top();
        sum += temp * temp;
        s.pop();
    }

    return sum;
}

int main()
{
    int p;
    cin >> p;

    int b, n, junk;
    for (int i = 0; i < p; i++) {
        cout << i + 1 << " ";

        cin >> junk >> b >> n;
        cout << ssd(base10_to(b, n)) << endl;

        if (i == p - 1) {
            cout << endl;
        }
    }

    return 0;
}
