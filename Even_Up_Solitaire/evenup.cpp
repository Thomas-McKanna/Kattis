#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> nums;
    int n, t;

    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> t;
        t %= 2;

        if (nums.empty() || nums.top() != t) {
            nums.push(t);
        } else {
            nums.pop();
        }
    }

    cout << nums.size() << endl;
}