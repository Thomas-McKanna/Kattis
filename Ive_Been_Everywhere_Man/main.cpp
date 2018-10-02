#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    int t;
    cin >> t;

    unordered_set<string> places;

    int n;
    string s;
    for (int i = 0; i < t; i++) {
        places.clear();
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> s;
            places.insert(s);
        }
        cout << places.size();
        if (i != t - 1) {
            cout << endl;
        }
    }

    return 0;
}
