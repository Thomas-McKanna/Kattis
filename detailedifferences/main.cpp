#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    string s1, s2;
    for (int i = 0; i < n; i++) {
        cin >> s1 >> s2;
        cout << s1 << endl;
        cout << s2 << endl;
        for (int j = 0; j < s1.length(); j++) {
            if (s1[j] != s2[j]) {
                cout << '*';
            } else {
                cout << '.';
            }
        }
        cout << endl;
    }

    return 0;
}
