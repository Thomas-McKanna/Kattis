#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

// Primary Measure = number of problems solved
// Secondary Measure = sum of rimes for right answers + 20*number of wrong submissions

int main()
{
    int minutes;
    char problem;
    string result;

    int score_solved = 0;
    int score_time = 0;

    int wrong_count[26] = {0};

    cin >> minutes;
    while (minutes != -1) {
        cin >> problem;
        cin >> result;

        if (result == "wrong") {
            wrong_count[problem - 'A']++;
        }

        if (result == "right") {
            score_solved++;
            score_time += minutes + 20*wrong_count[problem - 'A'];
        }

        cin >> minutes;
    }
    cout << score_solved << " " << score_time;
    return 0;
}
