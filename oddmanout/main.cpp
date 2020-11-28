#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    int n;
    cin >> n;

    unordered_map<int, bool> um;
    int g, temp;
    for (int i = 0; i < n; i++) {
        cin >> g;
        um.clear();
        for (int j = 0; j < g; j++) {
            cin >> temp;
            if (um[temp] == false) {
                um[temp] = true;
            } else {
                um[temp] = false;
            }
        }

        cout << "Case #" << i + 1 << ": ";
        for (auto p : um) {
            if (p.second == true) {
                cout << p.first;
                break;
            }
        }
        if (i != n - 1) {
            cout << endl;
        }
    }

    return 0;
}
