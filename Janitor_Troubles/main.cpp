// https://en.wikipedia.org/wiki/Bretschneider%27s_formula
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;

    double sp = (s1 + s2 + s3 + s4) / 2.0; // semi-perimeter

    cout << fixed << setprecision(15)
        << sqrt((sp - s1)*(sp - s2)*(sp - s3)*(sp - s4)) << endl;

    return 0;
}
