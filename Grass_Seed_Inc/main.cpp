#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double c;
    int L;
    cin >> c >> L;

    double width, length;
    double sum = 0;
    for (int i = 0; i < L; i++) {
        cin >> width >> length;
        sum += (width*length) * c;
    }

    cout << fixed << setprecision(8) << sum;

    return 0;
}
