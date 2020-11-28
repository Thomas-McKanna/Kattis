#include <iostream>
#include <set>

using namespace std;

int main()
{
    int L, H;
    cin >> L >> H;

    set<int> digits;
    int temp, digit;
    bool valid;
    int count = 0;
    for (int i = L; i <= H; i++) {
        digits.clear();
        valid = true;
        temp = i;
        while (temp != 0) {
            digit = temp % 10;

            // non-zero
            if (digit == 0) {
                valid = false;
                break;
            }

            // non-repeating
            if (digits.find(digit) == digits.end()) {
                digits.insert(digit);
            } else {
                valid = false;
                break;
            }

            // divisible
            if (i % digit != 0) {
                valid = false;
                break;
            }

            temp /= 10;
        }

        if (valid) {
            count++;
        }
    }

    cout << count;
    return 0;
}
