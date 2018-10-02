#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    string num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        cout << num.length();
        if (i != n - 1) {
            cout << endl;
        }
    }

    return 0;
}
