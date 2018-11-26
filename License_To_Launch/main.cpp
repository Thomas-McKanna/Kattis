#include <iostream>
#include <climits>
#include <utility>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int temp;
    std::pair<int, int> val_pos(INT_MAX, -1);
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (temp < val_pos.first) {
            val_pos.first = temp;
            val_pos.second = i;
        }
    }

    cout << val_pos.second;

    return 0;
}
