#include <iostream>
#include <set>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    set<string> words;

    string s;

    getline(cin, s);

    stringstream ss(s);

    do {
        ss >> s;
        if (words.insert(s).second == false) {
            cout << "no";
            return 0;
        }
    } while (!ss.eof());

    cout << "yes";
    return 0;
}
