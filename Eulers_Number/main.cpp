#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

char ctoi[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

long long factorial(int n) {
    if (n <= 0) {
        return 1;
    }

    int sum = 1;
    for (; n > 0; n--) {
        sum *= n;
    }

    return sum;
}

string div(int n) {
    string num;
    if (n == 1) {
        return string("1.000000000000000");
    } else {
        int curr = 10;
        num.push_back('0');
        num.push_back('.');
        for (int i = 0; i < 15; i++) {
            if (curr / n != 0) {
                num.push_back(ctoi[curr / n]);
                curr = ((curr - ((curr / n) * n)) * 10);
            } else {
                num.push_back('0');
                curr *= 10;
            }
        }
        return num;
    }
}

int main()
{
    int n;
    cin >> n;

    vector<string> nums;
    for (int i = 0; i <= n; i++) {
        nums.push_back(div(factorial(i)));
        cout << div(factorial(i)) << endl;
        cout << fixed << setprecision(15) << 1.0 / factorial(i) << endl;
        cout << "Factorial of " << i << ": " << factorial(i) << endl;
    }

    return 0;
}
