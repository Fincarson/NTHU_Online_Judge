#include "function.h"

namespace oj{
    SphereStone::SphereStone(double r, double pi){
        this->radius = r>0 ? r : 0;
        this->pi = pi>0 ? pi : 0;
        this->setSurfaceArea(4.0 * this->pi * this->radius * this->radius);
    }

    CuboidStone::CuboidStone(double l, double w, double h){
        this->length = l>0 ? l : 0;
        this->width = w>0 ? w : 0;
        this->height = h>0 ? h : 0;
        if(!this->length || !this->width || !this->height) this->setSurfaceArea(0.0);
        else this->setSurfaceArea(2.0 * ((this->length * this->width) + (this->length * this->height) + (this->width * this->height)));
    }

    CubeStone::CubeStone(double s):CuboidStone(s, s, s){}

    CylinderStone::CylinderStone(double r, double h, double pi){
        this->radius = r>0 ? r : 0;
        this->height = h>0 ? h : 0;
        this->pi = pi>0 ? pi : 0;
        if(!this->radius || !this->height || !this->pi) this->setSurfaceArea(0.0);
        else this->setSurfaceArea((2.0 * this->pi * this->radius * this->radius) + (2.0 * this->pi * this->radius * this->height));
    }

    CollectionBox::CollectionBox(){
        this->minArea = -1;
        this->maxArea = 0;
        this->totalArea = 0;
    }

    void CollectionBox::addStone(const Stone&stone){
        double value = stone.getSurfaceArea();
        if(value < this->minArea || this->minArea == -1) this->minArea = value;
        if(value > this->maxArea) this->maxArea = value;
        this->totalArea += value;
    }
}
