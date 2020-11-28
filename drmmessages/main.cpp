#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    string s;
    cin >> s;

    string first = s.substr(0, s.length() / 2);
    string second = s.substr(s.length() / 2, s.length());

    int sum = 0;
    for (int i = 0; i < first.length(); i++) {
        sum += first[i] - 'A';
    }
    for (int i = 0; i < first.length(); i++) {
        first[i] = 'A' + ((first[i] - 'A' + sum) % 26);
    }

    sum = 0;
    for (int i = 0; i < second.length(); i++) {
        sum += second[i] - 'A';
    }
    for (int i = 0; i < second.length(); i++) {
        second[i] = 'A' + ((second[i] - 'A' + sum) % 26);
    }

    for (int i = 0; i < first.length(); i++) {
        first[i] = 'A' + ((first[i] - 'A' + second[i] - 'A') % 26);
    }

    cout << first;

    return 0;
}
