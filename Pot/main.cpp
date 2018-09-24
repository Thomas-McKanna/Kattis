#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int sum = 0;
    int current;
    int p, temp;
    for (int i = 0; i < n; i++) {
        cin >> current;
        p = current % 10;
        current /= 10;
        temp = 1;
        for (int j = 0; j < p; j++) {
            temp *= current;
        }
        sum += temp;
    }
    cout << sum;
    return 0;
}
