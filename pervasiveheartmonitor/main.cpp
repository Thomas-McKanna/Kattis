#include <iostream>
#include <string>
#include <iomanip>
#include <regex>

using namespace std;

int main()
{
    cout << fixed << setprecision(6);

    smatch m;

    basic_regex<char> digits_ex("\\d+\\.?\\d*");
    basic_regex<char> name_ex("[^\\d\\.\\s]+");

    string s, temp, name;

    double total;
    int num;

    getline(cin, s);
    do {
        total = 0;
        num = 0;
        temp = s;

        while (regex_search(temp, m, digits_ex)) {
            for (auto it : m) {
                total += stod(it.str());
                num++;
            }
            temp = m.suffix();
        }

        name.clear();
        while (regex_search(s, m, name_ex)) {
            for (auto it : m) {
                name += " " + it.str();
            }
            s = m.suffix();
        }

        cout << total / num << name << endl;
        getline(cin, s);
    } while (!cin.eof());

    return 0;
}
