#include <iostream>
#include <vector>

using namespace std;

bool EVEN = false;
bool ODD = true;

bool matches_curr(int n, bool curr) {
    if (n % 2 == curr) {
        return true;
    } else {
        return false;
    }
}

bool coalesce(vector<int>& nums) {
    bool curr = EVEN;
    int i = 0;
    vector<int> groups;

    groups.push_back(0);
    while (i < nums.size()) {
        bool val = matches_curr(nums.at(i), curr);
        if (val) {
            groups.back() = (groups.back() + 1) % 2;
        } else {
            curr = !curr;
            groups.push_back(1);
        }
        i++;
    }

    if (groups.size() == nums.size() + 1) {
        return false;
    }

    nums.clear();

    curr = EVEN;
    for (auto& it : groups) {
        if (it != 0) {
            nums.push_back(curr);
        } 
        curr = !curr;
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        nums.push_back(temp);
    }

    for (auto& it : nums) {
        it %= 2;
    }


    while (coalesce(nums));

    cout << nums.size() << endl;
}