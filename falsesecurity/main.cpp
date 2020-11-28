#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
    unordered_map<char, string> ltom;
    unordered_map<string, char> mtol;

    vector<string> codes {".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
        "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
        "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

    {
        auto it = codes.begin();
        for (char c = 'A'; c <= 'Z'; c++) {
            ltom[c] = *it;
            mtol[*it] = c;
            it++;
        }
    }

    ltom['_'] = "..--";
    mtol["..--"] = '_';
    ltom[','] = ".-.-";
    mtol[".-.-"] = ',';
    ltom['.'] = "---.";
    mtol["---."] = '.';
    ltom['?'] = "----";
    mtol["----"] = '?';

    string encoded;
    stack<int> num_lens;
    string morse;
    string decoded;
    size_t pos;
    while (getline(cin, encoded).good()) {
        morse.clear();
        for (auto it : encoded) {
            morse.append(ltom[it]);
            num_lens.push(ltom[it].length());
        }
        decoded.clear();
        pos = 0;
        while (pos < morse.length()) {
            decoded.push_back(mtol[morse.substr(pos, num_lens.top())]);
            pos += num_lens.top();
            num_lens.pop();
        }

        cout << decoded << endl;
    }

    return 0;
}
