#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<char, int> m;
    int max_rank = 0;

    string s;
    for (int i = 0; i < 5; i++) {
        cin >> s;
        if (m.find(s[0]) == m.end()) {
            m[s[0]] = 1;
            if (max_rank == 0) {
                max_rank = 1;
            }
        } else {
            m[s[0]] += 1;
            if (max_rank < m[s[0]]) {
                max_rank = m[s[0]];
            }
        }
    }

    cout << max_rank;

    return 0;
}
