#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

int main() {
    int L;
    cin >> L;
    cin.ignore();

    string line;
    getline(cin, line);

    stack<char> delimiters;
    unordered_map<char, char> map;
    map[')'] = '(';
    map[']'] = '[';
    map['}'] = '{';

    for (int i = 0; i < line.length(); i++) {
        char c = line[i];
        if (c == '(' || c == '[' || c == '{') {
            delimiters.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (delimiters.empty() || delimiters.top() != map[c]) {
                cout << c << " " << i << endl;
                return 0;
            } else {
                delimiters.pop();
            }
        } 
    }

    cout << "ok so far" << endl;

    return 0;
}