#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int n, temp;
    int min, max;
    int ans;
    for (int i = 0; i < t; i++) {
        min = 100;
        max = -1;
        ans = 0;
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> temp;
            if (temp < min) {
                min = temp;
            }
            if (temp > max) {
                max = temp;
            }
        }
        ans = (max - min) * 2;
        cout << ans;
        if (i != t - 1) {
            cout << endl;
        }
    }

    return 0;
}
