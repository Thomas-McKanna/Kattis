#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int n, m;
    int junk;

    for (int i = 0; i < t; i++) {
        cin >> n >> m;
        for (int j = 0; j < m; j++) {
            cin >> junk >> junk;
        }
        cout << n - 1 << endl;
    }

    return 0;
}
