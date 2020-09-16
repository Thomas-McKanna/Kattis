#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, p_len;
    string s, p;
    bool found_pattern;

    cin >> n;
    cin.ignore();

    while (n--) {
        getline(cin, s);
        p_len = 1;
        while (p_len < s.size()) {
            found_pattern = true;
            p = s.substr(0, p_len);
            for (int i = 0; i < s.size(); i++) {
                if (s[i] != p[i % p_len]) {
                    found_pattern = false;
                    break;
                }
            }
            if (found_pattern)
                break;
            p_len++;
        }
        cout << p_len << endl;
    }

    return 0;
}