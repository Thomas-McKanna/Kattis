#include <iostream>

using namespace std;

int main()
{
    int e, f, c;
    cin >> e >> f >> c;

    int sum = e + f;
    int ans = 0;
    while (sum >= c) {
        sum = sum - c + 1;
        ans++;
    }

    cout << ans;

    return 0;
}
