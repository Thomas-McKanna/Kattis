#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double pi = atan(1)*4;

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    double step = pi*60/28;

    cout << fixed << setprecision(10);

    string s;
    int temp;
    double seconds;
    for (int i = 0; i < n; i++) {
        getline(cin, s);

        seconds = 1;
        if (s[0] == ' ') {
                s[0] = 'Z' + 1;
        } else if (s[0] == '\'') {
            s[0] = 'Z' + 2;
        }
        for (unsigned int j = 1; j < s.length(); j++) {
            if (s[j] == ' ') {
                s[j] = 'Z' + 1;
            } else if (s[j] == '\'') {
                s[j] = 'Z' + 2;
            }

            temp = abs(s[j - 1] - s[j]);
            if (temp > 14) {
                seconds += step*(28-temp) / 15 + 1;
            } else {
                seconds += step*temp / 15 + 1;
            }
        }

        cout << seconds;
        if (i != n - 1) {
            cout << endl;
        }
    }

    return 0;
}
