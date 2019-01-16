#include <iostream>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;

    size_t a_row, b_col;
    for (size_t i = 0; i < a.length(); i++) {
        for (size_t j = 0; j < b.length(); j++) {
            if (a.at(i) == b.at(j)) {
                a_row = j;
                b_col = i;
                goto print_crossword;
            }
        }
    }

    print_crossword:
    for (size_t i = 0; i < b.length(); i++) {
        for (size_t j = 0; j < a.length(); j++) {
            if (i == a_row) {
                cout << a.at(j);
            } else if (j == b_col) {
                cout << b.at(i);
            } else {
                cout << '.';
            }
        }
        cout << endl;
        }

    return 0;
}
