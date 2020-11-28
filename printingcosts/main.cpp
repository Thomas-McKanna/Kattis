#include <iostream>

using namespace std;

int main() {
    cout << "dict = {\n";
    string symbol, value;
    for (int i = 0; i < 94; i++) {
        cin >> symbol >> value;
        cout << "\t'" << symbol << "': " << value << ",\n";
    }
    cout << "}";
    return 0;
}