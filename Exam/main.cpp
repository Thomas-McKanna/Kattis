#include <iostream>

using namespace std;

int main()
{
    int k;
    string you, other;
    cin >> k >> you >> other;

    int max_score = 0;
    for (size_t i = 0; i < you.length(); i++) {
        if (you.at(i) == other.at(i) && k > 0) {
            max_score++;
            k--;
        } else if (you.at(i) != other.at(i)) {
            max_score++;
        }
    }

    cout << max_score - k;
    return 0;
}
