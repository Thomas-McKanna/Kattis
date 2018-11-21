#include <iostream>

using namespace std;

int main()
{
    int currentPlayer;
    cin >> currentPlayer;

    int n;
    cin >> n;

    int timeLeft = 210; // 3 min 30 sec

    int time;
    char response;
    for (int i = 0; i < n; i++) {
        cin >> time >> response;
        // check if end game during turn
        if (timeLeft - time <= 0) {
            break;
        } else {
            timeLeft -= time;
            if (response == 'T') {
                currentPlayer = (currentPlayer + 1) % 8;
            }
        }
    }

    if (currentPlayer == 0) {
        cout << "8";
    } else {
        cout << currentPlayer;
    }


    return 0;
}
