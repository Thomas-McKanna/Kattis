#include <iostream>
#include <utility>
#include <cmath>
#include <vector>

using namespace std;

class Shape {
public:
    virtual bool in_bounds(pair<int, int>& target)=0;

    virtual ~Shape() {}
};

class Rectangle : public Shape {
private:
    pair<int, int> bot_left;
    pair<int, int> top_right;

public:
    bool in_bounds(pair<int, int>& target) {
        if ((target.first >= bot_left.first && target.first <= top_right.first)
                && target.second >= bot_left.second && target.second <= top_right.second) {
            return true;
        } else {
            return false;
        }
    }

    Rectangle(int x1, int y1, int x2, int y2) {
        bot_left = pair<int, int>(x1, y1);
        top_right = pair<int, int>(x2, y2);
    }
};

class Circle : public Shape {
private:
    pair<int, int> center;
    int radius;

    double distance(pair<int, int>& p1, pair<int, int>& p2) {
        return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
    }

public:
    bool in_bounds(pair<int, int>& target) {
        if (distance(target, center) <= radius) {
            return true;
        } else {
            return false;
        }
    }

    Circle(int x, int y, int r) {
        center = pair<int, int>(x, y);
        radius = r;
    }
};

int main()
{
    int m;
    cin >> m;

    vector<Shape*> shapes;
    string temp;
    int t1, t2, t3, t4;
    for (int i = 0; i < m; i++) {
        cin >> temp;
        if (temp.front() == 'r') {
            cin >> t1 >> t2 >> t3 >> t4;
            shapes.push_back(new Rectangle(t1, t2, t3, t4));
        } else {
            cin >> t1 >> t2 >> t3;
            shapes.push_back(new Circle(t1, t2, t3));
        }
    }

    int n;
    cin >> n;

    int count;
    pair<int, int> target;
    for (int i = 0; i < n; i++) {
        count = 0;
        cin >> t1 >> t2;
        target = pair<int, int>(t1, t2);
        for (auto it : shapes) {
            if (it->in_bounds(target)) {
                count++;
            }
        }
        cout << count << endl;
    }

    for (auto it : shapes) {
        delete it;
    }

    return 0;
}
