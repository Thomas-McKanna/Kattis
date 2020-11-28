#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

int MONEY = 0;
int INCENSE = 1;
int JEWEL = 2;

int main() {
    int n;
    cin >> n;
    cin.ignore();

    unordered_map<char, int> map;
    map['b'] = MONEY;
    map['t'] = INCENSE;
    map['j'] = JEWEL;

    string adventure;
    while (n--) {
        stack<int> backpack;
        getline(cin, adventure);
        bool success = true;
        for (int i = 0; i < adventure.length(); i++) {
            if (adventure[i] == '$') backpack.push(MONEY);
            else if (adventure[i] == '|') backpack.push(INCENSE);
            else if (adventure[i] == '*') backpack.push(JEWEL);
            else if (adventure[i] != '.') {
                if (backpack.empty() 
                        || backpack.top() != map[adventure[i]]) {
                    success = false;
                    break;
                } else {
                    backpack.pop();
                }
            }
        }
        if (success && backpack.empty()) {
            cout << "YES" <<endl;
        } else {
            cout << "NO" <<endl;
        }
    }

    return 0;
}