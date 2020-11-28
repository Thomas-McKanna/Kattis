#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    string s;
    int sum = 0;
    bool chains_casted, success;
    for (int i = 0; i < n; i++) {
        chains_casted = false;
        success = true;
        cin >> s;
        for (auto j = s.begin(); j != s.end(); j++) {
            if (*j == 'D' && chains_casted) {
                success = false;
                break;
            } else if (*j == 'C') {
                chains_casted = true;
            } else {
                chains_casted = false;
            }
        }
        if (success) {
            sum++;
        }
    }

    cout << sum;

    return 0;
}
