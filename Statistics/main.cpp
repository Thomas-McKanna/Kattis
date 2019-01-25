#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    int counter = 1;
    int temp;
    string line;
    set<int> nums;
    stringstream s;
    while (getline(cin, line)) {
        nums.clear();
        s = stringstream(line);
        s >> temp;
        while (s >> temp) {
            nums.insert(temp);
        }

        auto smallest = nums.begin();
        auto largest = nums.rbegin();
        cout << "Case " << counter++ << ": " << *smallest
            << " " << *largest << " " << *largest - *smallest
                << endl;
    }
    return 0;
}
