#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    bool found_smaller;
    string temp;
    for (int i = 0; i < t; i++) {
        found_smaller = false;
        cin >> temp;
        for (int i = temp.length() - 1; i >= 0; i--) {
            if (!found_smaller && temp.at(i) != '0') {
                temp.at(i)--;
                found_smaller = true;
            }
        }
        cout << stoi(temp) << endl;
    }

    return 0;
}
