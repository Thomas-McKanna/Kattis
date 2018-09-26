#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair<int, string> &i, pair<int, string> &j) {
    return i.first < j.first;
}

int main()
{
    int n;
    cin >> n;

    string first, second;

    vector<pair<int, string>> cups;

    for (int i = 0; i < n; i++) {
        cin >> first >> second;
        if (first[0] >= '0' && first[0] <= '9') {
            cups.push_back(pair<int, string>(stoi(first) / 2, second));
        } else {
            cups.push_back(pair<int, string>(stoi(second), first));
        }
    }

    sort(cups.begin(), cups.end(), compare);

    for (auto it = cups.begin(); it != cups.end(); it++) {
        cout << it->second;
        if (next(it) != cups.end()) {
            cout << endl;
        }
    }

    return 0;
}
