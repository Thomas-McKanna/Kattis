#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    string first, second;
    cin >> first >> second;

    bool fail = false;

    if (n % 2) {
        for (size_t i = 0; i < first.length(); i++) {
            if (first.at(i) == second.at(i)) {
                fail = true;
            }
        }
    } else if (first != second) {
        fail = true;
    }

    if (fail) {
        cout << "Deletion failed";
    } else {
        cout << "Deletion succeeded";
    }

    return 0;
}
