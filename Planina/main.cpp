#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int side_len = 2;

    for (int i = 0; i < n; i++) {
        side_len = 2*side_len - 1;
    }

    cout << side_len*side_len;

    return 0;
}
