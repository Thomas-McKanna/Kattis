#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <unordered_map>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int iter = 1;

    string temp;
    int start_pos;
    set<string> names;
    unordered_map<string, int> counts;

    while (n != 0 && iter < 6) {
        cin.ignore();
        names.clear();
        counts.clear();
        for (int i = 0; i < n; i++) {
            getline(cin, temp);
            start_pos = temp.rfind(" ") + 1;
            temp = temp.substr(start_pos);

            for (auto &ch : temp) {
                ch = tolower(ch);
            }
            names.insert(temp);
            if (counts.find(temp) == counts.end()) {
                counts[temp] = 1;
            } else {
                counts[temp] += 1;
            }
        }

        cout << "List " << iter << ":" << endl;

        for (auto &n : names) {
            cout << n << " | " << counts[n] << endl;
        }

        iter++;
        cin >> n;
    }
    return 0;
}
