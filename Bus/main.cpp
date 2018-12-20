#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;

    vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    for (int i = 2; i <= 30; i++) {
        nums.push_back(nums.at(i - 1) * 2 + 1);
    }

    int k;
    for (int i = 0; i < t; i++) {
        cin >> k;
        cout << nums.at(k) << endl;
    }

    return 0;
}
