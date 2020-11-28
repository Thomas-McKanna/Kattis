#include <iostream>

using namespace std;

int main()
{
    string input, output;
    cin >> input;

    char last = ' ';
    for (int i = 0; i < input.length(); i++) {
        if (input[i] != last) {
            output += input[i];
            last = input[i];
        }
    }

    cout << output;

    return 0;
}
