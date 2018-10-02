#include <iostream>

using namespace std;

int main()
{
    int l, x;
    cin >> l >> x;

    string s;
    int in_out;
    int people = 0;
    int turned_away = 0;
    for (int i = 0; i < x; i++) {
        cin >> s >> in_out;
        if (s == "enter") {
            if (people + in_out > l) {
                turned_away++;
                continue;
            }
            people += in_out;
        } else {
            people -= in_out;
        }
    }

    cout << turned_away;

    return 0;
}
