#include <iostream>
#include <cmath>

using namespace std;

class Point3D {
    double x;  // x-coordinate
    double y;  // y-coordinate
    double z;  // z-coordinate

   public:
    Point3D(double x = 0, double y = 0, double z = 0) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    double distance(Point3D that) {
        return sqrt((this->x - that.x) * (this->x - that.x) +
                    (this->y - that.y) * (this->y - that.y) +
                    (this->z - that.z) * (this->z - that.z));
    }
};

int main() {
    Point3D a(1, 1, 1), b(1, 2, 3);
    double dist = a.distance(b);
    cout << "Distance between (1,1,1) and (1,2,3) = " << dist << endl;
}
