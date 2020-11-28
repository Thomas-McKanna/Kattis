#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    string temp;
    for (int i = 0; i < t; i++) {
        cin >> temp;
        for (int i = temp.length() - 1; i >= 0; i--) {
            if (temp.at(i) != '0') {
                temp.at(i)--;
                break;
            }
        }
        cout << stoi(temp) << endl;
    }

    return 0;
}
