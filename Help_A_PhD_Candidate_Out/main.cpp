#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    string line;

    int pos;
    for (int i = 0; i < n; i++) {
        cin >> line;
        if (line == "P=NP") {
            cout << "skipped" << endl;
        } else {
            pos = line.find("+");
            cout << atoi(line.substr(0, pos).c_str()) + atoi(line.substr(pos + 1).c_str()) << endl;
        }
    }

    return 0;
}
