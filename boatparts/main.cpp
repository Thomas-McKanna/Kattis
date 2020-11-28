#include <iostream>
#include <set>

using namespace std;

int main()
{
    size_t p, n;

    cin >> p >> n;

    set<string> items;
    string temp;
    bool all_parts_replaced = false;
    for (size_t i = 0; i < n; i++) {
        cin >> temp;
        items.insert(temp);
        if (items.size() >= p) {
            cout << i + 1;
            all_parts_replaced = true;
            break;
        }
    }

    if (!all_parts_replaced) {
        cout << "paradox avoided";
    }

    return 0;
}
