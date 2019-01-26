#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int ans = n - 2;

    if (ans < 1) {
        ans = 1;
    }

    cout << ans << endl;

    return 0;
}
