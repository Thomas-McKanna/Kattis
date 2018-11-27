#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    std::string a;
    cin >> a;

    string adrian = "ABC";
    int adrian_len = 3;
    string bruno = "BABC";
    int bruno_len = 4;
    string goran = "CCAABB";
    int goran_len = 6;

    int counter = 0;

    int adrian_score = 0;
    int bruno_score = 0;
    int goran_score = 0;

    int max_score = 0;

    for (auto i = a.begin(); i != a.end(); i++) {
        if (adrian.at(counter % adrian_len) == *i) {
            adrian_score++;
            if (adrian_score > max_score) {
                max_score = adrian_score;
            }
        }

        if (bruno.at(counter % bruno_len) == *i) {
            bruno_score++;
            if (bruno_score > max_score) {
                max_score = bruno_score;
            }
        }

        if (goran.at(counter % goran_len) == *i) {
            goran_score++;
            if (goran_score > max_score) {
                max_score = goran_score;
            }
        }

        counter++;
    }

    cout << max_score << endl;

    if (adrian_score == max_score) {
        cout << "Adrian" << endl;
    }

    if (bruno_score == max_score) {
        cout << "Bruno" << endl;
    }

    if (goran_score == max_score) {
        cout << "Goran";
    }

    return 0;
}
