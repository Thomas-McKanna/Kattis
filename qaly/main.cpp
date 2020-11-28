#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    double ans = 0;
    double q, y;
    for (int i = 0; i < n; i++) {
        cin >> q >> y;
        ans += q * y;
    }

    cout << ans;

    return 0;
}
