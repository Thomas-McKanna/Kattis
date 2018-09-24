#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int num_t = 0;
    int num_c = 0;
    int num_g = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'T') {
            num_t++;
        }
        if (s[i] == 'C') {
            num_c++;
        }
        if (s[i] == 'G') {
            num_g++;
        }
    }

    int score = 0;

    score += num_t*num_t + num_c*num_c + num_g*num_g;

    while (num_t > 0 && num_c > 0 && num_g > 0) {
        num_t--;
        num_c--;
        num_g--;
        score += 7;
    }

    cout << score;

    return 0;
}
