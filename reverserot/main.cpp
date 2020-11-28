#include <iostream>

using std::cout;
using std::cin;
using std::string;
using std::endl;

int main()
{
    int rotate;
    string message;
    cin >> rotate;
    while (rotate != 0) {
        cin >> message;
        for (unsigned int i = 0; i < message.length(); i++) {
            // Convert _ and . so they are logically behind Z
            if (message[i] == '_') {
                message[i] = 'Z' + 1;
            } else if (message[i] == '.') {
                message[i] = 'Z' + 2;
            }
            // Do the rotation
            message[i] = 'A' + ((message[i] - 'A' + rotate) % 28);
            // Switch back to _ and .
            if (message[i] == 'Z' + 1) {
                message[i] = '_';
            } else if (message[i] == 'Z' + 2) {
                message[i] = '.';
            }
        }
        // Print in reversed order
        for (int i = message.length() - 1; i > -1; i--) {
            cout << message[i];
        }
        cout << endl;
        cin >> rotate;
    }
    return 0;
}
