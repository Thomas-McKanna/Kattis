#include <iostream>
#include <iomanip>

using namespace std;

double heartrate(int b, double p) {
    return (60 * b) / p;
}

int main()
{
    int n;
    cin >> n;

    cout << fixed << setprecision(4);

    int b;
    double p;
    for (int i = 0; i < n; i++) {
        cin >> b >> p;
        cout << (60 * (b - 1)) / p << " ";
        cout << (60 * b) / p << " ";
        cout << (60 * (b + 1)) / p;
        if (i != n - 1) {
            cout << endl;
        }
    }

    return 0;
}
