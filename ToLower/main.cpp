#include <iostream>

using namespace std;

int main()
{
    int p, t;

    cin >> p >> t;

    string temp;
    int count = 0;
    bool moveon;
    for (int i = 0; i < p; i++) {
        moveon = false;
        for (int j = 0; j < t; j++) {
            cin >> temp;
            if (!moveon && temp.length() > 1) {
                for (size_t k = 1; k < temp.length(); k++) {
                    if (temp.at(k) <= 'Z') {
                        count++;
                        moveon = true;
                        break;
                    }
                }
            }
        }
    }

    cout << p - count;

    return 0;
}
