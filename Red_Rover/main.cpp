#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    string s;
    cin >> s;

    unordered_map<string, int> m;

    for (size_t i = 0; i < s.length(); i++) {
        for (size_t j = i; j < s.length(); j++) {
            if (m.find(s.substr(i, j - i + 1)) == m.end()) {
                m[s.substr(i, j - i + 1)] = 1;
            } else {
                m[s.substr(i, j - i + 1)]++;
            }
        }
    }

    int max_saved = 0;
    for (auto it : m) {
        cout << it.first << ": " << it.second << endl;
        if ((int) it.first.length() * it.second - it.second - (int) it.first.length() > max_saved) {
            max_saved = (int) it.first.length() * it.second - it.second - (int) it.first.length();
        }
    }

    cout << s.length() << endl;
    cout << max_saved << endl;
    cout << s.length() - max_saved;

    return 0;
}
