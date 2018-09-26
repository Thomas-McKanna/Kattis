#include <iostream>

using namespace std;

int main()
{
    int r, c, zr, zc;
    cin >> r >> c >> zr >> zc;

    char a[r][c];

    string line;

    for (int i = 0; i < r; i++) {
        cin >> line;
        for (int j = 0; j < c; j++) {
            a[i][j] = line[j];
        }
    }

    for (int i = 0; i < r; i++) {
        for (int p = 0; p < zr; p++) {
            for (int j = 0; j < c; j++) {
                for (int k = 0; k < zc; k++) {
                    cout << a[i][j];
                }
            }
            cout << endl;
        }
    }

    return 0;
}
