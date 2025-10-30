#ifndef FUNCTION_H
#define FUNCTION_H

namespace oj {
    class Stone {
        double surfaceArea;

    public:
        double getSurfaceArea() const;

    protected:
        void setSurfaceArea(double surfaceArea);
    };

    class SphereStone : public Stone {
        double radius;
        double pi;
    public:
        SphereStone(double, double);
    };

    class CuboidStone : public Stone {
        double length;
        double width;
        double height;
    public:
        CuboidStone(double, double, double);
    };

    class CubeStone : public CuboidStone {
    public:
        CubeStone(double);
    };

    class CylinderStone : public Stone {
        double radius;
        double height;
        double pi;
    public:
        CylinderStone(double, double, double);
    };

    class CollectionBox {
        double minArea;
        double maxArea;
        double totalArea;

    public:
        CollectionBox();
        void addStone(const Stone &stone);
        double getMinArea() const { return minArea; }
        double getMaxArea() const { return maxArea; }
        double getTotalArea() const { return totalArea; }
    };
}

#endif // FUNCTION_H