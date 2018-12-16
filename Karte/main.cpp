#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<string> p, k, h, t;

    char iter = '1';
    string temp;
    for (int i = 0; i < 9; i++) {
        temp.clear();
        temp.push_back('0');
        temp.push_back(iter);

        p.insert("P" + temp);
        k.insert("K" + temp);
        h.insert("H" + temp);
        t.insert("T" + temp);
        iter++;
    }

    iter = '0';
    for (int i = 0; i < 4; i++) {
        temp.clear();
        temp.push_back('1');
        temp.push_back(iter);

        p.insert("P" + temp);
        k.insert("K" + temp);
        h.insert("H" + temp);
        t.insert("T" + temp);
        iter++;
    }

    string input;
    cin >> input;

    bool double_found = false;
    size_t i = 0;
    while (i < input.length()) {
        temp = input.substr(i, 3);

        switch (temp.front()) {
            case 'P':
                if (p.find(temp) == p.end()) {
                    double_found = true;
                    break;
                } else {
                    p.erase(temp);
                }
                break;
            case 'K':
                if (k.find(temp) == k.end()) {
                    double_found = true;
                    break;
                } else {
                    k.erase(temp);
                }
                break;
            case 'H':
                if (h.find(temp) == h.end()) {
                    double_found = true;
                    break;
                } else {
                    h.erase(temp);
                }
                break;
            case 'T':
                if (t.find(temp) == t.end()) {
                    double_found = true;
                    break;
                } else {
                    t.erase(temp);
                }
                break;
        }

        if (double_found) {
            cout << "GRESKA";
            return 0;
        }

        i += 3;
    }

    cout << p.size() << " " << k.size()
        << " " << h.size() << " " << t.size();

    return 0;
}
