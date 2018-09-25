#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    cout << n << ":" << endl;

    if (n == 3) {
        cout << "2,1";
        return 0;
    }

    vector<string> answers;

    for (int i = 2; i < n; i++) {
        if ((n + i - 1) % (i + i - 1) == 0) {
            answers.push_back(to_string(i) + "," + to_string(i - 1));

        } else if (n % (i + i - 1) == 0) {
            answers.push_back(to_string(i) + "," + to_string(i - 1));
        }

        if (n % i == 0) {
            answers.push_back(to_string(i) + "," + to_string(i));
        }
    }

    for (auto it = answers.begin(); it != answers.end(); it++) {
        cout << *it;
        if (next(it) != answers.end()) {
            cout << endl;
        }
    }

    return 0;
}
