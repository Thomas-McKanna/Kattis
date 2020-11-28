#include <iostream>
#include <vector>
#include <map>

using namespace std;

const string ANS_NEITHER = "neither";
const string ANS_BIN = "binary";
const string ANS_DEC = "decimal";

const char BIN_SYMBOL = '0';
const char DEC_SYMBOL = '1';
const char MARKER = '#';

const int ROW_BEG_BOUND = -1;
const int COL_BEG_BOUND = -1;
int ROW_END_BOUND = 0; // will be set
int COL_END_BOUND = 0; // will be set

const vector<int> UP {-1, 0};
const vector<int> DOWN {1, 0};
const vector<int> LEFT {0, -1};
const vector<int> RIGHT {0, 1};

const int VERT = 0;
const int HORI = 1;

bool find_path(vector<vector<char>> &the_map, char open, int r, int c, int target_r, int target_c) {
    // base case 1: out of bounds
    if (r <= ROW_BEG_BOUND || r >= ROW_END_BOUND) {
        return false;
    }
    if (c <= COL_BEG_BOUND || c >= COL_END_BOUND) {
        return false;
    }
    // base case 2: wrong symbol (went on invalid path)
    if (the_map[r][c] != open) {
        return false;
    }
    // base case 3: reached target
    if (r == target_r && c == target_c) {
        return true;
    }
    // recursive case
    char saved_char = the_map[r][c]; // Save current character on this spot
    the_map[r][c] = MARKER; // Mark spot

    map<int, vector<int>> move_order;

    move_order[r - target_r] = UP;
    move_order[target_r - r] = DOWN;
    move_order[c - target_c] = LEFT;
    move_order[target_c - c] = RIGHT;

    for (auto pair : move_order) {
        if (find_path(the_map, open, r + pair.second.at(VERT), c + pair.second.at(HORI), target_r, target_c)) {
            return true;
            the_map[r][c] = saved_char; 
        } 
    }

    // All paths failed, so remove mark
    the_map[r][c] = saved_char; 
    return false;
}

int main() {

    int r, c;
    cin >> r >> c;

    ROW_END_BOUND = r;
    COL_END_BOUND = c;

    cin.ignore();

    vector<vector<char>> the_map(r, vector<char>());

    // Reading in the map
    string temp;
    for (int i = 0; i < r; i++) {
        getline(cin, temp);
        for (auto c : temp) {
            the_map.at(i).push_back(c);
        }
    }

    int n;
    cin >> n;

    string answer;
    char symbol;
    int r1, c1, r2, c2;
    for (int i = 0; i < n; i++) {
        cin >> r1 >> c1 >> r2 >> c2;
        
        if (the_map[r1 - 1][c1 - 1] != the_map[r2 - 1][c2 - 1]) {
            cout << ANS_NEITHER << endl;
            continue;
        } else if (the_map[r1 - 1][c1 - 1] == '0') {
            answer = ANS_BIN;
            symbol = BIN_SYMBOL;
        } else {
            answer = ANS_DEC;
            symbol = DEC_SYMBOL;
        }

        if (find_path(the_map, symbol, r1 - 1, c1 - 1, r2 - 1, c2 - 1)) {
            cout << answer << endl;
        } else {
            cout << ANS_NEITHER << endl;
        }
    }

    return 0;
}
