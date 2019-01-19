#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t, r, c;
    cin >> t;

    vector<vector<char>> img;

    for (int i = 0; i < t; i++) {
        cin >> r >> c;

        img = vector<vector<char>>(r, vector<char>(c));

        for (int j = 0; j < r; j++) {
            for (int k = 0; k < c; k++) {
                cin >> img.at(j).at(k);
            }
        }

        cout << "Test " << i + 1 << endl;
        for (auto m = img.rbegin(); m != img.rend(); m++) {
            for (auto n = m->rbegin(); n != m->rend(); n++) {
                cout << *n;
            }
            cout << endl;
        }
    }

    return 0;
}
