#include <cmath>
#include <iostream>

using namespace std;

class Point {
    double x;  // x-coordinate
    double y;  // y-coordinate

   public:
    Point(double x = 0, double y = 0) {
        this->x = x;
        this->y = y;
    }

    double operator-(const Point& that) {
        return sqrt((this->x - that.x) * (this->x - that.x) +
                    (this->y - that.y) * (this->y - that.y));
    }

    void setX(double x) { this->x = x; }
    void setY(double y) { this->y = y; }
    double getX() { return x; }
    double getY() { return y; }

};

int main() {
    Point a(1, 1), b(5, 4);
    double dist = a - b;
    cout << "Distance between (1,1) and (5,4) = " << dist << endl;
}
