#include <iostream>
#include <iomanip>

using namespace std;

string target = "welcome to code jam", text;

int dp(int i, int j) {
    if (i == target.length()) return 1;
    if (j == text.length()) return 0;
    
    int c = 0;
    // k new from here
    if (text[j] == 'w' && i != 0) c += dp(0, j);
    else {
        // take match
        if (text[j] == target[i]) c += dp(i + 1, j + 1);
        // don't take
        c += dp(i, j + 1);
    }
    
    return c % 10000;
}

int main() {
    int T;
    cin >> T;
    cin.ignore();

    cout << setfill('0');

    for (int i = 1; i <= T; i++) {
        getline(cin, text);
        cout << "Case #" << i << ": " << setw(4) << dp(0, 0) << endl;
    }

    return 0;
}