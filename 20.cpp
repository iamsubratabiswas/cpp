#include <iostream>
#include <time.h>
#include <cmath>

using namespace std;

// return randim number from [lo, hi)
double getRandom(double lo, double hi) { 
    double random = (double) rand() / RAND_MAX;
    random *= (hi-lo);
    random += lo;
    return random;
}

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

class WirelessDevide {
    Point3D location;
    int uid;
    double tRange;

   public:
    WirelessDevide() {
        uid = 0;
        tRange = 0;
    }
    
    WirelessDevide(Point3D location, int uid, double tRange) {
        this->location = location;
        this->uid = uid;
        this->tRange = tRange;
    }

    Point3D getLocation() {
        return location;
    }

    void setLocation(Point3D location) {
        this->location = location;
    }

    double getRange() {
        return tRange;
    }

    int getUid() {
        return uid;
    }

    bool inRange(WirelessDevide that) {
        if (this->location.distance(that.location) <= this->tRange)
            return true;
        return false;
    }
};

int main() {
    int n = 10;
    WirelessDevide arr[n];
    for (int i = 0; i < n; i++) {
        Point3D location = Point3D(getRandom(-n,n), getRandom(-n,n), getRandom(-n,n));
        arr[i] = WirelessDevide(location, i, getRandom(1,1.5*n));
    }

    for (int i = 0; i < n; i++) {
        cout << "Neighbour(s) of " << i << " : ";
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            if (arr[i].inRange(arr[j])) cout << j << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        Point3D location = Point3D(getRandom(-n,n), getRandom(-n,n), getRandom(-n,n));
        arr[i].setLocation(location);
    }

    cout << "Locations randomly changed\n";
    
    for (int i = 0; i < n; i++) {
        cout << "Neighbour(s) of " << i << " : ";
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            if (arr[i].inRange(arr[j])) cout << j << " ";
        }
        cout << endl;
    }
}
