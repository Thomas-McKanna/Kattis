#include <iostream>
#include <vector>

using namespace std;

bool contains_building(vector<vector<char>> &v, int r, int c) {
    if (v[r][c] == '#' || v[r+1][c] == '#' || v[r][c+1] =='#' || v[r+1][c+1] == '#') {
        return true;
    } else {
        return false;
    }
}

int num_cars(vector<vector<char>> &v, int r, int c) {
    int count = 0;
    if (v[r][c] == 'X') {
        count++;
    }

    if (v[r][c+1] == 'X') {
        count++;
    }

    if (v[r+1][c] == 'X') {
        count++;
    }

    if (v[r+1][c+1] == 'X') {
        count++;
    }

    return count;
}

int main()
{
    int r, c;
    cin >> r >> c;

    vector<vector<char>> m(r, vector<char>(c));
    vector<int> spots(5, 0);

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> m[i][j];
        }
    }


    for (int i = 0; i < r - 1; i++) {
        for (int j = 0; j < c - 1; j++) {
            if (contains_building(m, i, j)) {
                continue;
            } else {
                spots.at(num_cars(m, i, j))++;
            }
        }
    }

    for (auto it = spots.begin(); it != spots.end(); it++) {
        cout << *it << endl;
    }

    return 0;
}
