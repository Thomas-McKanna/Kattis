#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v;

    int temp;
    for (int i = 0; i < 4; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    std::sort(v.begin(), v.end());

    std::cout <<  v[0] * v[2];

    return 0;
}
