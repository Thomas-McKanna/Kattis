#include <cstring>
#include <set>
#include <cmath>
#include <iostream>

using namespace std;

int main() {
    int x;
    cin >> x;

    set<int> primes;

    int sqrt_x = floor(sqrt(x));

    bool prime[sqrt_x+1];
    memset(prime, true, sizeof(prime));

    for (int p=2; p<=sqrt_x; p++)
    {
        // If prime[p] is not changed, then it is prime
        if (prime[p] == true)
        {
            primes.insert(p);
            // Update all multiples of p greater than or
            // equal to the square of it
            // numbers which are multiple of p and are
            // less than p^2 are already been marked.
            for (int i=p*p; i<=sqrt_x; i += p) {
                prime[i] = false;
            }
        }
    }

    int count = 0;
    bool broke_out;
    while (x > 1) {
        broke_out = false;
        for (auto it = primes.rbegin(); it != primes.rend(); it++) {
            if (x % *it == 0) {
                count++;
                x /= *it;
                broke_out = true;
                break;
            }
        }
        if (!broke_out) {
            // It must be prime, we are done.
            count++;
            break;
        }
    }

    cout << count << endl;

    return 0;
}
