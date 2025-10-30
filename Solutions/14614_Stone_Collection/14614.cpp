#include "function.h"
#include <cassert>
#include <iomanip>
#include <iostream>

using namespace std;

namespace oj {
    double Stone::getSurfaceArea() const {
        return surfaceArea;
    }
    void Stone::setSurfaceArea(double surfaceArea) {
        this->surfaceArea = surfaceArea;
    }
}

int main() {
    using namespace oj;

    string s;
    double a, b, c;

    CollectionBox box;

    while (cin >> s) {
        if (s == "Sphere") {
            cin >> a >> b;
            SphereStone sphere(a, b);
            // cout << "Sphere: " << sphere.getSurfaceArea() << endl;
            box.addStone(sphere);
        } else if (s == "Cuboid") {
            cin >> a >> b >> c;
            CuboidStone cuboid(a, b, c);
            // cout << "Cuboid: " << cuboid.getSurfaceArea() << endl;
            box.addStone(cuboid);
        } else if (s == "Cube") {
            cin >> a;
            CubeStone cube(a);
            // cout << "Cube: " << cube.getSurfaceArea() << endl;
            box.addStone(cube);
        } else if (s == "Cylinder") {
            cin >> a >> b >> c;
            CylinderStone cylinder(a, b, c);
            // cout << "Cylinder: " << cylinder.getSurfaceArea() << endl;
            box.addStone(cylinder);
        } else {
            assert(false && "Unknown shape type");   // should not reach here
        }
    }

    cout << fixed << setprecision(2);
    cout << "Minimum Area: " << box.getMinArea() << endl;
    cout << "Maximum Area: " << box.getMaxArea() << endl;
    cout << "Total Area:   " << box.getTotalArea() << endl;
}