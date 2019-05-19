#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    string word;
    cin >> word;

    unordered_set<char> keyword;
    for (auto c : word) {
        keyword.insert(c);
    }

    string alpha;
    cin >> alpha;

    int count = 0;

    for (auto c : alpha) {
        auto curr = keyword.find(c);
        if (curr != keyword.end()) {
            keyword.erase(curr);
        } else {
            count++;
            if (count > 10) {
                cout << "LOSE" << endl;
                return 0;
            }
        }

        if (keyword.empty()) break;
    }
    cout << "WIN" << endl;
    return 0;
}
