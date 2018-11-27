#include <iostream>

using namespace std;

int main()
{
    int g, s, c;
    cin >> g >> s >> c;

    int total = 3 * g + 2 * s + 1 * c;

    std::string dominion = "";
    std::string treasure = "Copper";

    // Treasure card
    if (total >= 8) {
        dominion = "Province";
    } else if (total >= 5) {
        dominion = "Duchy";
    } else if (total >= 2) {
        dominion = "Estate";
    }

    if (total >= 6) {
        treasure = "Gold";
    } else if (total >= 3) {
        treasure = "Silver";
    }

    if (dominion == "") {
        cout << treasure;
    } else {
        cout << dominion << " or " << treasure;
    }

    return 0;
}
