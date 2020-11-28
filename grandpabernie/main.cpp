#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    unordered_map<string, vector<int>> m;

    int n;
    cin >> n;

    string s;
    unsigned int y;
    for (int i = 0; i < n; i++) {
        cin >> s >> y;
        (m[s]).push_back(y);
    }

    for (auto &pair : m) {
        auto start = pair.second.begin();
        auto end = pair.second.end();
        sort(start, end);
    }

    /*
    for (auto &pair : m) {
        cout << pair.first << ": ";
        for (auto it = pair.second.begin(); it != pair.second.end(); it++) {
             cout << *it << " ";
        }
        cout << endl;
    }
    */

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        cin >> s >> y;
        cout << m[s][y - 1];
        if (i != q - 1) {
            cout << endl;
        }
    }

    return 0;
}
