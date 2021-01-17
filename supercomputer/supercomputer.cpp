#include <vector>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <cstring>

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

  ll rsq(int i, int j) { return rsq(j) - rsq(i-1); } // inc/exclusion

  // updates value of the i-th element by v (v can be +ve/inc or -ve/dec)
  void update(int i, ll v) {
    for (; i < (int)ft.size(); i += LSOne(i))
      ft[i] += v;
  }
};

int main() {
    ll N, K, i, l, r;
    bool bits[1000001];
    memset(bits, false, sizeof(bits));
    string op;
    stringstream output;
    cin >> N >> K;
    FenwickTree ft(N);
    while (K--) {
        cin >> op;
        if (op == "F") {
            cin >> i;
            if (bits[i]) 
                ft.update(i, -1);
            else 
                ft.update(i, 1);
            bits[i] = !bits[i];
        } else {
            cin >> l >> r;
            output << ft.rsq(l, r) << "\n";
        }
    }
    cout << output.str();
    return 0;
}
