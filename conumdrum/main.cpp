#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int pos = 0;
    int counter = 0;

    for (int i = 0; i < s.length(); i++) {
        if (pos == 0 && s[i] != 'P') {
            counter++;
        } else if (pos == 1 && s[i] != 'E') {
            counter++;
        } else if (pos == 2 && s[i] != 'R') {
            counter++;
        }
        pos = (pos + 1) % 3;
    }

    cout << counter;

    return 0;
}
