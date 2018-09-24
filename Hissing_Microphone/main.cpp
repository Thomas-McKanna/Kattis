#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    bool flag = false;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 's') {
            if (flag) {
                cout << "hiss";
                return 0;
            }
            flag = true;
        } else if (flag) {
            flag = false;
        }
    }
    cout << "no hiss";
    return 0;
}
