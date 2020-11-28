#include <iostream>
#include <utility>

using namespace std;

int main()
{
    int w, l;
    cin >> w >> l;

    pair<int, int> thinks, actual;

    char dir;
    int n, dist;
    while (w != 0 || l != 0) {
        cin >> n;
        thinks.first = 0;
        thinks.second = 0;
        actual.first = 0;
        actual.second = 0;
        for (int i = 0; i < n; i++) {
            cin >> dir >> dist;
            switch (dir) {
                case 'u':
                    thinks.second += dist;
                    if (actual.second + dist > l - 1) {
                        actual.second = l - 1;
                    } else {
                        actual.second += dist;
                    }
                    break;
                case 'r':
                    thinks.first += dist;
                    if (actual.first + dist > w - 1) {
                        actual.first = w - 1;
                    } else {
                        actual.first += dist;
                    }
                    break;
                case 'd':
                    thinks.second -= dist;
                    if (actual.second - dist < 0) {
                        actual.second = 0;
                    } else {
                        actual.second -= dist;
                    }
                    break;
                case 'l':
                    thinks.first -= dist;
                    if (actual.first - dist < 0) {
                        actual.first = 0;
                    } else {
                        actual.first -= dist;
                    }
            }
        }
        cout << "Robot thinks " << thinks.first << " " << thinks.second << endl;
        cout << "Actually at " << actual.first << " " << actual.second << endl;
        cout << endl;
        cin >> w >> l;
    }

    return 0;
}
