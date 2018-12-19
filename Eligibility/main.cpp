#include <iostream>
#include <vector>

using namespace std;

struct student {
    string name;
    int study_year;
    int birth_year;
    int courses;
};

int main()
{
    int n;
    cin >> n;

    vector<student> students;
    student temp;
    string s;
    int num;
    for (int i = 0; i < n; i++) {
        cin >> s;
        temp.name = s;
        cin >> s;
        s = s.substr(0, 4);
        temp.study_year = atoi(s.c_str());
        cin >> s;
        s = s.substr(0, 4);
        temp.birth_year = atoi(s.c_str());
        cin >> num;
        temp.courses = num;
        students.push_back(temp);
    }

    for (auto &it : students) {
        cout << it.name << " ";
        if (it.study_year >= 2010 || it.birth_year >= 1991) {
            cout << "eligible" << endl;
        } else if (it.courses >= 41) {
            cout << "ineligible" << endl;
        } else {
            cout << "coach petitions" << endl;
        }
    }

    return 0;
}
