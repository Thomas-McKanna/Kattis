#include <iostream>
#include <cstdlib>
#include <list>
#include <string>
#include<fstream>
#include <iomanip>

using namespace std;

/*
int main()
{
    //ifstream Inputfile;
    //Inputfile.open("random_input");

    list<int> cookies;

    string d;
    int x;
    int temp = 0;
    auto middle = cookies.begin();
    while (getline(cin, d).good()) {
        if (d == "#") {
            bool decrease_middle = false;
            if ((cookies.size() - 1) % 2 == 0) {
                decrease_middle = true;
            }

            cout << *middle << endl;

            //cout << "Removed " << *middle << endl;
            auto temp = middle;
            if (decrease_middle == true) {
                middle--;
            } else {
                middle++;
            }

            cookies.erase(temp);


            for (auto it = cookies.begin(); it != cookies.end(); it++) {
                cout << setw(5) << *it;
            }
            cout << endl;
            for (auto it = cookies.begin(); it != cookies.end(); it++) {
                cout << "    ";
                if (middle == it) {
                    cout << "^";
                } else {
                    cout << " ";
                }
            }
            cout << endl;





        } else {
            x = stoi(d);
            bool decrease_middle = false;
            bool increase_middle = false;
            if ((cookies.size() + 1) % 2 == 0 && x >= *middle) {
                decrease_middle = true;
            } else if ((cookies.size() + 1) % 2 != 0 &&x < *middle) {
                increase_middle = true;
            }

            bool was_inserted = false;
            if (middle == cookies.end()) {
                cookies.push_front(x);
                middle = cookies.begin();
            } else {
                for (auto it = cookies.begin(); it != cookies.end(); it++) {
                    if (*it <= x) {
                        cookies.insert(it, stoi(d));
                        was_inserted = true;
                        break;
                    }
                }
                if (!was_inserted) {
                    cookies.push_back(x);
                }
            }
            if (decrease_middle) {
                middle--;
            } else if (increase_middle) {
                middle++;
            }


            cout << "Inserted " << x << endl;
            for (auto it = cookies.begin(); it != cookies.end(); it++) {
                cout << setw(5) << *it;
            }
            cout << endl;
            for (auto it = cookies.begin(); it != cookies.end(); it++) {
                cout << "    ";
                if (middle == it) {
                    cout << "^";
                } else {
                    cout << " ";
                }
            }
            cout << endl;




        }
    }

    return 0;
}



int main()
{
    list<int> cookies;

    string d;
    int x;
    auto middle = cookies.begin();
    while (getline(cin, d).good()) {
        if (d == "#") {
            bool decrease_middle = false;
            if ((cookies.size() - 1) % 2 == 0) {
                decrease_middle = true;
            }

            cout << *middle << endl;

            //cout << "Removed " << *middle << endl;
            auto temp = middle;
            if (decrease_middle == true) {
                middle--;
            } else {
                middle++;
            }

            cookies.erase(temp);


            for (auto it = cookies.begin(); it != cookies.end(); it++) {
                cout << *it << " ";
            }
            cout << endl;
            for (auto it = cookies.begin(); it != cookies.end(); it++) {
                if (*middle == *it) {
                    cout << "^";
                } else {
                    cout << " ";
                }
                cout << " ";
            }
            cout << endl;




        } else {
            x = stoi(d);
            bool decrease_middle = false;
            bool increase_middle = false;
            if ((cookies.size() + 1) % 2 == 0 && x >= *middle) {
                decrease_middle = true;
            } else if ((cookies.size() + 1) % 2 != 0 &&x < *middle) {
                increase_middle = true;
            }

            if (middle == cookies.end()) {
                cookies.push_front(x);
                middle = cookies.begin();
            } else {
                for (auto it = cookies.begin(); it != cookies.end(); it++) {
                    if (*it <= x) {
                        cookies.insert(it, stoi(d));
                        break;
                    }
                }
            }
            if (decrease_middle) {
                middle--;
            } else if (increase_middle) {
                middle++;
            }



            cout << "Inserted " << x << endl;
            for (auto it = cookies.begin(); it != cookies.end(); it++) {
                cout << *it << " ";
            }
            cout << endl;
            for (auto it = cookies.begin(); it != cookies.end(); it++) {
                if (middle == it) {
                    cout << "^";
                } else {
                    cout << " ";
                }
                cout << " ";
            }
            cout << endl;



        }
    }

    return 0;
}
*/
