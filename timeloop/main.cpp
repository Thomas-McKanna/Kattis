#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            cout << i + 1 << " Abracadabra";
        } else {
            cout << i + 1 << " Abracadabra" << endl;
        }
    }
    return 0;
}
