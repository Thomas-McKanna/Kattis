#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    double a, i;

    cin >> a >> i;

    int guess = 1;
    while (true) {
        if (ceil(guess / a) == i) {
            cout << guess;
            return 0;
        }
        guess++;
    }

    return 0;
}
