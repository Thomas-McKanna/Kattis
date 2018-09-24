#include <iostream>

using namespace std;

int main()
{
    string input;
    cin >> input;

    int len = input.length();

    string abrev;
    if (len != 0) {
        abrev.push_back(input[0]);
    }

    if (len == 1) {
        cout << abrev;
        return 0;
    }

    bool flag = false;
    for (int i = 1; i < input.length(); i++) {
        if (flag) {
            abrev.push_back(input[i]);
            flag = false;
        } else if (input[i] == '-') {
            flag = true;
        }
    }

    cout << abrev;

    return 0;
}
