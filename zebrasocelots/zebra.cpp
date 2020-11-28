#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    long long ans = 0;
    char c;
    while (n--) {
        cin >> c;
        ans += c== 'O' ? 1L << n : 0;
    }

    cout << ans << endl;

    return 0;
}