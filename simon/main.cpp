#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    string line;
    for (int i = 0; i < n; i++) {
        getline(cin, line);

        if (line.find("Simon says") == 0) {
            cout << line.substr(11) << endl;
        }
    }

    return 0;
}
