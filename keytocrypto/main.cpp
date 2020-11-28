#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    string cipher, k;
    cin >> cipher >> k;

    size_t key_len = k.length();

    for (size_t i = 0; i < cipher.length(); i++) {
        k.push_back( 'A' + (((cipher.at(i) - 'A') - (k.at(i) - 'A')) + 26) % 26 );
    }

    for (size_t i = key_len; i < k.length(); i++) {
        cout << k.at(i);
    }

    return 0;
}
