#include <iostream>

using namespace std;

string replace(string s, string r) {
    size_t pos = 0;
    while (pos < s.length()) {
        pos = s.find(r);
        if (pos != string::npos) {
            s.replace(pos, r.length(), "M");
            pos++;
        } else {
            break;
        }
    }
    return s;
}

int main()
{
    string s;
    cin >> s;

    size_t len = s.length();

    string temp;
    size_t temp_len;
    for (size_t i = 0; i < s.length() - 1; i++) {
        for (size_t j = i + 1; j < s.length(); j++) {
            temp = s.substr(i, j - i + 1);
            temp_len = temp.length();
            temp = replace(s, temp);

            len = min(temp.length() + temp_len, len);
        }
    }

    cout << len << endl;

    return 0;
}
