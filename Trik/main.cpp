#include <iostream>

using namespace std;

int main()
{

    bool cups[3];

    cups[0] = true;
    cups[1] = false;
    cups[2] = false;

    string s;
    cin >> s;

    bool temp;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'A') {
            temp = cups[0];
            cups[0] = cups[1];
            cups[1] = temp;
        }
        if (s[i] == 'B') {
            temp = cups[1];
            cups[1] = cups[2];
            cups[2] = temp;
        }
        if (s[i] == 'C') {
            temp = cups[0];
            cups[0] = cups[2];
            cups[2] = temp;
        }
    }

    if (cups[0]) cout << 1;
    if (cups[1]) cout << 2;
    if (cups[2]) cout << 3;

    return 0;
}
