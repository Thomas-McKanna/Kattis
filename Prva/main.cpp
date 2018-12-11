#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int r, c;
    cin >> r >> c;

    set<string> words;
    vector<string> lines;

    string temp;
    for (int i = 0; i < r; i++) {
        cin >> temp;
        lines.push_back(temp);
    }

    for (int i = 0; i < c; i++) {
        temp.clear();
        for (int j = 0; j < r; j++) {
            temp.push_back(lines[j][i]);
        }
        lines.push_back(temp);
    }

    size_t i, start;
    for (auto &it : lines) {
            i = 0;
            start = 0;
            while (i < it.length()) {
                if (it.at(i) != '#') {
                    i++;
                } else {
                    if (i - start > 1) {
                        words.insert(it.substr(start, i - start));
                    }
                    i++;
                    start = i;
                }
            }
            if (it.length() - start > 1) {
                words.insert(it.substr(start));
            }
    }

    cout << *(words.begin());

    return 0;
}
