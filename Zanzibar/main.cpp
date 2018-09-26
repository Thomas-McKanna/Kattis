#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int ans;
    int next, prev;
    for (int i = 0; i < n; i++) {
        ans = 0;
        prev = 1;
        cin >> next;
        while (next != 0) {
            if (next > 2*prev) {
                ans += next - (2*prev);
            }
            prev = next;
            cin >> next;
        }
        cout << ans;
        if (i != n - 1) {
            cout << endl;
        }
    }

    return 0;
}
