#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double pi = atan(1)*4;

int to_int(char x)
{
    return x == ' ' ? 26 : x == '\'' ? 27 : x - 'A';
}

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    double step = pi*60/28;

    cout << fixed << setprecision(20);

    string s;
    int temp;
    int runs, pickups;
    for (int i = 0; i < n; i++) {
        getline(cin, s);

        runs = 0;
        pickups = 1;
        for (unsigned int j = 1; j < s.length(); j++) {
            temp = abs(to_int(s[j - 1]) - to_int(s[j]));
            if (temp > 14) {
                runs += 28 - temp;
            } else {
                runs += temp;
            }
            pickups++;
        }

        cout << step*runs/15 + pickups;
        if (i != n - 1) {
            cout << endl;
        }
    }

    return 0;
}
