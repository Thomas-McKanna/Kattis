#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int current;
    int expenses = 0;
    for (int i = 0; i < n; i++) {
        cin >> current;
        if (current < 0) {
            expenses += -current;
        } 
    }
    cout << expenses << endl;

    return 0;
}
