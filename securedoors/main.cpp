#include <iostream>
#include <set>
#include <utility>

using namespace std;

int main()
{
    int n;
    cin >> n;

    set<string> inside;

    string action, name;
    for (int i = 0; i < n; i++) {
        cin >> action >> name;
        cout << name;
        if (action == "entry") {
            auto p = inside.insert(name);
            cout << " entered";
            if (p.second == false) {
                 cout << " (ANOMALY)";
            }
        } else {
            int a = inside.erase(name);
            cout << " exited";
            if (a == 0) {
                cout << " (ANOMALY)";
            }
        }
        cout << endl;
    }

    return 0;
}
