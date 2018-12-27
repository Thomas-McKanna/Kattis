#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    unordered_map<string, int> digits;
    digits["**** ** ** ****"] = 0;
    digits["  *  *  *  *  *"] = 1;
    digits["***  *****  ***"] = 2;
    digits["***  ****  ****"] = 3;
    digits["* ** ****  *  *"] = 4;
    digits["****  ***  ****"] = 5;
    digits["****  **** ****"] = 6;
    digits["***  *  *  *  *"] = 7;
    digits["**** ***** ****"] = 8;
    digits["**** ****  ****"] = 9;

    vector<string> code;

    string line;
    getline(cin, line);

    size_t pos = 0;
    string temp;
    while (pos < line.length()) {
        temp = line.substr(pos, 3);
        code.push_back(temp);
        pos += 4;
    }

    for (int i = 0; i < 4; i++) {
        getline(cin, line);
        pos = 0;
        while (pos < line.length()) {
            temp = line.substr(pos, 3);
            code.at(pos / 4) = code.at(pos / 4) + temp;
            pos += 4;
        }
    }

    int multiplier = 1;
    int ans = 0;
    for (auto it = code.rbegin(); it != code.rend(); it++) {
        auto val = digits.find(*it);
        if (val != digits.end()) {
            ans += val->second * multiplier;
            multiplier *= 10;
        } else {
            cout << "BOOM!!";
            return 0;
        }
    }

    if (ans % 6 == 0) {
        cout << "BEER!!";
    } else {
        cout << "BOOM!!";
    }

    return 0;
}
