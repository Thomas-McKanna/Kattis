#include <vector>
#include <stdio.h>
#include <iostream>
#include <sstream>

using namespace std;

#define LSOne(S) ((S) & -(S))                    // the key operation

typedef long long ll;                            // for extra flexibility
typedef vector<ll> vll;
typedef vector<int> vi;

class FenwickTree {                              // index 0 is not used
private:
  vll ft;                                        // internal FT is an array
public:
  FenwickTree(int m) { ft.assign(m+1, 0); }      // create an empty FT

  ll rsq(int j) {                                // returns RSQ(1, j)
    ll sum = 0;
    for (; j; j -= LSOne(j))
      sum += ft[j];
    return sum;
  }

  // updates value of the i-th element by v (v can be +ve/inc or -ve/dec)
  void update(int i, ll v) {
    for (; i < (int)ft.size(); i += LSOne(i))
      ft[i] += v;
  }
};

int main() {
    ll N, Q, i, d;
    string op;
    stringstream output;
    cin >> N >> Q;
    FenwickTree ft(N);
    while (Q--) {
        cin >> op;
        if (op == "+") {
            cin >> i >> d;
            ft.update(i + 1, d);
        } else {
            cin >> i;
            output << ft.rsq(i) << "\n";
        }
    }
    cout << output.str();
    return 0;
}
