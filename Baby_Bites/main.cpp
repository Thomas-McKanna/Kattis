#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    bool done = false;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s != "mumble") {
            if (stoi(s) != i + 1) {
                cout << "something is fishy";
                done = true;
                break;
            }
        }
    }

    if(!done) {
        cout << "makes sense";
    }

    return 0;
}
