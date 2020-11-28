#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    string schools[12];
    string names[12];

    int size = 0;

    string school, name;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        cin >> school >> name;
        for (int j = 0; j < size; j++) {
            if (school.compare(schools[j]) == 0) {
                // Team has already won
                flag = true;
                break;
            }
        }
        if (flag) {
            flag = false;
        } else {
            schools[size] = school;
            names[size] = name;
            size++;
        }
        if (size == 11 + 1) {
            break;
        }
    }

    for (int i = 0; i < 12; i++) {
        cout << schools[i] << " " << names[i];
        if (i != n - 1) {
            cout << endl;
        }
    }

    return 0;
}
