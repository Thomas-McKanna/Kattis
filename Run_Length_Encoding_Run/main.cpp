#include <iostream>
#include <stdlib.h>

using namespace std;

char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

string encode(string s) {
    string out;
    int count = 0;
    char prev = s.front();
    for (unsigned int i = 1; i < s.length(); i++) {
        count++;
        if (s[i] != prev) {
            out.push_back(prev);
            out.push_back(digits[count]);
            count = 0;
        }
        prev = s[i];
    }

    out.push_back(prev);
    out.push_back(digits[count + 1]);

    return out;
}

string decode(string s) {
    string out;
    char first, second;
    for (unsigned int i = 0; i < s.length(); i += 2) {
        first = s[i];
        second = s[i + 1];
        for (int j = 0; j < second - '0'; j++) {
            out.push_back(first);
        }
    }

    return out;
}

int main()
{
    char mode;
    cin >> mode;

    string input;
    cin >> input;

    if (mode == 'E') {
        cout << encode(input);
    } else if (mode == 'D') {
        cout << decode(input);
    }

    return 0;
}
