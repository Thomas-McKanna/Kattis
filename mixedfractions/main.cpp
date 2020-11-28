#include <iostream>

using namespace std;

int main()
{
    int num, den;

    cin >> num >> den;
    while (num != 0 && den != 0) {
        cout << num / den << " ";
        cout << num % den << " / " << den << endl;

        cin >> num >> den;
    }

    return 0;
}
