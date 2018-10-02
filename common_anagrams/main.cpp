#include <iostream>
#include <string>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
    int t;
    cin >> t;

    int len;
    string a, b;
    for (int it = 0; it < t; it++) {
        cin >> len;
        cin >> a >> b;

        /*
        int a_letters[26] = {0};
        int b_letters[26] = {0};

        for (int i = 0; i < len; i++) {
            (a_letters[a[i] - 'A'])++;
            (b_letters[b[i] - 'A'])++;
        }


        cout << "A:" << endl;
        for (int i = 0; i < 26; i++) {
            cout << char('A' + i) << ": " << a_letters[i] << endl;
        }
        cout << "A:" << endl;
        for (int i = 0; i < 26; i++) {
            cout << char('A' + i) << ": " << b_letters[i] << endl;
        }


        int ans = 0;
        int shift_count = len;
        bool flag;
        for (int i = 1; i <= len; i++) {
            // shift over len / i times
            for (int j = 0; j < shift_count; j++) {
                flag = true;
                for (int k = 0; k < i; k++) {
                    if (a_letters[k + j] != b_letters[k + j]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    ans++;
                    shift_count--;
                    continue;
                }
            }
            shift_count--;
        }
        cout << "Case #" << it + 1 << ": " << ans << endl;
        */
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());

        cout << a << endl;
        cout << b << endl;
    }

    return 0;
}
