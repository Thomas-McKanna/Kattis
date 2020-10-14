#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int n, num_iter, permutation[20];
    string message, temp;

    cin >> n;
    
    while (n != 0) {
        for (int i = 0; i < n; i++) {
            cin >> permutation[i];
        }
        cin.ignore();
        getline(cin, message);

        while (message.length() % n != 0) {
            message += " ";
        }
        num_iter = message.length() / n;

        for (int i = 0; i < num_iter; i++) {
            temp = message.substr(i * n, n);
            for (int j = 0; j < n; j++) {
                message[i * n + j] = temp[permutation[j] - 1];
            }
        }
        cout << "'" << message << "'" << endl;

        cin >> n;
    }


    return 0;
}