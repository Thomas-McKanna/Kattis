#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore();
    string message;
    int square_len, mult;
    while (N--) {
        getline(cin, message);
        square_len = 1;
        while (square_len * square_len < message.length()) square_len++;
        for (int i = message.length(); i < square_len * square_len; i++) {
            message += "*";
        }

        char grid[square_len][square_len];
        mult = -1;
        for (int i = 0; i < square_len * square_len; i++) {
            if (i % square_len == 0) mult++;
            grid[mult][i % square_len] = message[i];
        }

        for (int i = 0; i < square_len; i++) {
            for (int j = square_len - 1; j >= 0; j--) {
                if (grid[j][i] != '*')
                    cout << grid[j][i];
            }
        }
        cout << endl;
    }

    return 0;
}