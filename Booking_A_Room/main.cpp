#include <iostream>
#include <set>

using namespace std;

int main()
{
    int r, n;
    cin >> r >> n;

    set<int> rooms;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        rooms.insert(temp);
    }

    for (int i = 1; i <= r; i++) {
        if (rooms.find(i) == rooms.end()) {
            cout << i;
            return 0;
        }
    }

    cout << "too late";
    return 0;
}
