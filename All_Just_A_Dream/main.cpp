#include <iostream>
#include <stack>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    int num;
    cin >> num;

    std::stack<string> events();

    char c;
    for (int i = 0; i < num; i++) {
        cin >> c;
        switch (c) {
            case 'E':
            case 'D':
            case 'S':
            return 0;
        }
    }
    return 0;
}
