#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string s;
    cin >> s;

    vector<int> alpha(26, 0);

    for (auto i : s) {
        alpha.at(i - 'a')++;
    }

    bool allow_odd = true;

    int ans = 0;
    for (auto i : alpha) {
        if (i % 2 != 0) {
            if (allow_odd) {
                allow_odd = false;
            } else {
                ans++;
            }
        }
    }

    cout << ans;

    return 0;
}
