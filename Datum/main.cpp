#include <iostream>

using namespace std;

int main()
{
    int first_day_of_month[12];
    first_day_of_month[0] = 4;
    first_day_of_month[1] = 0;
    first_day_of_month[2] = 0;
    first_day_of_month[3] = 3;
    first_day_of_month[4] = 5;
    first_day_of_month[5] = 1;
    first_day_of_month[6] = 3;
    first_day_of_month[7] = 6;
    first_day_of_month[8] = 2;
    first_day_of_month[9] = 4;
    first_day_of_month[10] = 0;
    first_day_of_month[11] = 2;

    int d, m;
    cin >> d >> m;

    while (d > 7) {
        d = d -7;
    }

    int ans;
    ans = (first_day_of_month[m - 1] + d - 1) % 7;

    if (ans == 0) {
        cout << "Sunday";
    } else if (ans == 1) {
        cout << "Monday";
    } else if (ans == 2) {
        cout << "Tuesday";
    } else if (ans == 3) {
        cout << "Wednesday";
    } else if (ans == 4) {
        cout << "Thursday";
    } else if (ans == 5) {
        cout << "Friday";
    } else if (ans == 6) {
        cout << "Saturday";
    }

    return 0;
}
