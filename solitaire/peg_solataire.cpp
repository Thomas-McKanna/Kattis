#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, int> memo;

int opt(string board) {
    if (memo.find(board) != memo.end()) {
        return memo[board];
    }

    bool found_move = false;
    int max_moves = -1;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i*9+j] == 'o') {
                // left
                if (j - 2 >= 0 && board[i*9+j-1] == 'o' && board[i*9+j-2] == '.') {
                    found_move = true;
                    board[i*9+j] = '.';
                    board[i*9+j-1] = '.';
                    board[i*9+j-2] = 'o';
                    max_moves = max(max_moves, 1 + opt(board));
                    board[i*9+j] = 'o';
                    board[i*9+j-1] = 'o';
                    board[i*9+j-2] = '.';
                }
                // right
                if (j + 2 < 9 && board[i*9+j+1] == 'o' && board[i*9+j+2] == '.') {
                    found_move = true;
                    board[i*9+j] = '.';
                    board[i*9+j+1] = '.';
                    board[i*9+j+2] = 'o';
                    max_moves = max(max_moves, 1 + opt(board));
                    board[i*9+j] = 'o';
                    board[i*9+j+1] = 'o';
                    board[i*9+j+2] = '.';
                }
                // up
                if (i - 2 >= 0 && board[(i-1)*9+j] == 'o' && board[(i-2)*9+j] == '.') {
                    found_move = true;
                    board[i*9+j] = '.';
                    board[(i-1)*9+j] = '.';
                    board[(i-2)*9+j] = 'o';
                    max_moves = max(max_moves, 1 + opt(board));
                    board[i*9+j] = 'o';
                    board[(i-1)*9+j] = 'o';
                    board[(i-2)*9+j] = '.';
                }
                // down
                if (i + 2 < 5 && board[(i+1)*9+j] == 'o' && board[(i+2)*9+j] == '.') {
                    found_move = true;
                    board[i*9+j] = '.';
                    board[(i+1)*9+j] = '.';
                    board[(i+2)*9+j] = 'o';
                    max_moves = max(max_moves, 1 + opt(board));
                    board[i*9+j] = 'o';
                    board[(i+1)*9+j] = 'o';
                    board[(i+2)*9+j] = '.';
                }
            }
        }
    }

    if (!found_move) {
        return memo[board] = 0;
    } else {
        return memo[board] = max_moves;
    }
}

int main() {
    int N;
    cin >> N;
    cin.ignore();

    string board, temp;

    while (N--) {
        memo.clear();

        board = "";
        for (int i = 0; i < 5; i++) {
            getline(cin, temp);
            board += temp;
        }

        int ans = opt(board);

        int peg_count = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i*9+j] == 'o') peg_count++;
            }
        }

        cout << peg_count - ans << " " << ans << endl;

        getline(cin, temp); // ignore empty line
    }

    return 0;
}