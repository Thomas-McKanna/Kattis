#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int num_flies(vector<string> &lines, int r, int s, int k, const pair<int, int> &coord) {
    int count = 0;
    for (int i = coord.first; i < coord.first + k - 2; i++) {
        for (int j = coord.second; j < coord.second + k - 2; j++) {
            if (lines.at(i).at(j) == '*') {
                count++;
            }
        }
    }
    return count;
}

void draw_racket(vector<string> &lines, const pair<int, int> &coord, int k) {
    const int start_r = coord.first - 1;
    const int start_c = coord.second - 1;
    int i;
    // first line
    lines.at(start_r).at(start_c) = '+';
    for (i = start_c + 1; i < start_c + k - 1; i++) {
        lines.at(start_r).at(i) = '-';
    }
    lines.at(start_r).at(i) = '+';
    // middle
    for (i = start_r + 1; i < start_r + k - 1; i++) {
        lines.at(i).at(start_c) = '|';
        lines.at(i).at(start_c + k - 1) = '|';
    }
    // last line
    int end_r = i;
    lines.at(end_r).at(start_c) = '+';
    for (i = start_c + 1; i < start_c + k - 1; i++) {
        lines.at(end_r).at(i) = '-';
    }
    lines.at(end_r).at(i) = '+';
}

int main()
{
    int r, s, k;
    cin >> r >> s >> k;
    cin.ignore();

    vector<string> lines;

    string temp;
    for (int i = 0; i < r; i++) {
        getline(cin, temp);
        lines.push_back(temp);
    }

    pair<int, pair<int, int>> max;
    max.first = 0;
    int temp_num;
    pair<int, int> temp_coord;
    for (int i = 1; i < r + 2 - k; i++) {
        for (int j = 1; j < s + 2 - k; j++) {
            temp_coord.first = i;
            temp_coord.second = j;
            temp_num = num_flies(lines, r, s, k, temp_coord);
            if (temp_num > max.first) {
                max.first = temp_num;
                max.second = temp_coord;
            }
        }
    }

    cout << max.first << endl;

    draw_racket(lines, max.second, k);
    for (auto &it : lines) {
        cout << it << endl;
    }

    return 0;
}
