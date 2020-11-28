#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    vector<string> words;
    while (cin >> s) {
        words.push_back(s);
    }

    set<string> compounds;
    for (auto i : words) {
        for (auto j : words) {
            if (i != j) {
                compounds.insert(i + j);
            }
        }
    }

    for (auto i : compounds) {
        cout << i << endl;
    }

    return 0;
}
