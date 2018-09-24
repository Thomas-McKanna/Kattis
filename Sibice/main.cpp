#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n, w, h;

    cin >> n >> w >> h;

    double max_length;
    max_length = sqrt(w*w + h*h);
    max_length = floor(max_length);

    int current;
    for (int i = 0; i < n; i++) {
        cin >> current;
        if (current <= max_length) {
            cout << "DA";
        } else {
            cout << "NE";
        }
        if (i != n - 1) {
            cout << endl;
        }
    }

    return 0;
}
