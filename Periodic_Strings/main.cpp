#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    for (int k = 1; k <= s.size(); k++) {
        if (s.size() % k == 0) {
            bool valid = true;
            string pattern = s.substr(0, k);
            int offset = 0;
            for (int i = 0; i < s.size() / k; i++) {
                if (!valid) break;
                for (int j = 0; j < k; j++) {
                    if (s[i * k + j] != pattern[(offset + j) % k]) {
                        valid = false;
                        break;
                    }
                }
                offset = (offset + k - 1) % k;
            }
            if (valid) {
                cout << k << endl;
                return 0;
            }
        }
    }
    return 0;
}