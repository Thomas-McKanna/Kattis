#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<char> letters;

    int n;
    cin >> n;
    cin.ignore();

    string s;
    for (int i = 0; i < n; i++) {

        for (char c = 'a'; c <= 'z'; c++) {
            letters.insert(c);
        }

        getline(cin, s);

        for (auto it : s) {
            letters.erase(tolower(it));
        }

        if (letters.empty()) {
            cout << "pangram" << endl;
        } else {
            cout << "missing ";
            for (auto it : letters) {
                cout << it;
            }
            cout << endl;
        }
    }

    return 0;
}
