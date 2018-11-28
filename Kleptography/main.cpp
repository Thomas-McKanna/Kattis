#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    std::string plain, cipher;
    cin >> plain >> cipher;

    for (int i = 0; i < m - n; i++) {
        for (int k = 0; k < 26; k++) {
            if (cipher.at(m - 1 - i) - 'a' == (plain.at(n - 1) - 'a' + k) % 26) {
                plain.insert(plain.begin(), 'a' + k);
                break;
            }
        }
    }

    cout << plain << endl;

    return 0;
}
