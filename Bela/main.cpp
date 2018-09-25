#include <iostream>

using namespace std;

int main()
{
    int n;
    char b;
    cin >> n >> b;

    string card;
    char value, suit;
    int sum = 0;
    for (int i = 0; i < 4*n; i++) {
        cin >> card;
        value = card[0];
        suit = card[1];

        switch (value) {
        case 'A':
            sum += 11;
            break;
        case 'K':
            sum += 4;
            break;
        case 'Q':
            sum += 3;
            break;
        case 'J':
            if (suit == b) {
                sum += 20;
                break;
            }
            sum += 2;
            break;
        case 'T':
            sum += 10;
            break;
        case '9':
            if (suit == b) {
                sum += 14;
                break;
            }
            break;
        default:
            break;
        }
    }

    cout << sum;

    return 0;
}
