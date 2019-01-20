#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

int main()
{
    string quadkey;
    cin >> quadkey;

    size_t side_len = pow(2, quadkey.length());

    pair<int, int> pos(0, 0);

    int dist;
    for (auto c : quadkey) {
        dist = side_len / 2;
        switch (c) {
            case '1':
                pos.first += dist;
                break;
            case '2':
                pos.second += dist;
                break;
            case '3':
                pos.first += dist;
                pos.second += dist;
            default:
                break;
        }
        side_len = dist;
    }

    cout << quadkey.length() << " " << pos.first << " " << pos.second << endl;

    return 0;
}
