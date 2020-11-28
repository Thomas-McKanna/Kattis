#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    string s;
    getline(cin, s);

    int whitespace = 0;
    int lowercase = 0;
    int uppercase = 0;
    int symbols = 0;

    for (unsigned int i = 0; i < s.length(); i++) {
        if (s[i] == '_') {
            whitespace++;
        } else if (s[i] >= 'a' && s[i] <= 'z') {
            lowercase++;
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            uppercase++;
        } else {
            symbols++;
        }
    }

    double total = whitespace + lowercase + uppercase + symbols;

    cout << fixed << setprecision(7);

    cout << whitespace / total << endl;
    cout << lowercase / total << endl;
    cout << uppercase / total << endl;
    cout << symbols / total;
}
