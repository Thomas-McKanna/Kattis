#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<pair<int, int>> movements = {
    pair<int, int>(-2, -1),
    pair<int, int>(-1, -2),
    pair<int, int>(1, 2),
    pair<int, int>(2, 1),
    pair<int, int>(-2, -1),
    pair<int, int>(-1, -2),
    pair<int, int>(1, -2),
    pair<int, int>(2, -1)
};

bool in_bounds(pair<int, int>& target) {
    if (target.first < 0 || target.first > 4
            || target.second < 0 || target.second > 4) {
        return false;
    } else {
        return true;
    }
}



int main()
{
    vector<vector<bool>> board(5, vector<bool>(5));

    int count = 0;
    char input;
    bool is_knight;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> input;
            if (input == '.') {
                is_knight = false;
            } else {
                is_knight = true;
                count++;
            }
            board.at(i).at(j) = is_knight;
        }
    }

    if (count != 9) {
        cout << "invalid";
        return 0;
    }

    pair<int, int> temp;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (board.at(i).at(j) == true) {
                temp.first = i;
                temp.second = j;
                for (auto move : movements) {
                    move.first += i;
                    move.second += j;
                    if (in_bounds(move) && board.at(move.first).at(move.second) == true) {
                        cout << "invalid";
                        return 0;
                    }
                }
            }
        }
    }

    cout << "valid";
    return 0;
}
