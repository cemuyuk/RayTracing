#ifndef SPHERE_H
#define SPHERE_H

#include "Shape.h"

namespace Raytracer148 {
class Sphere : public Shape {
public:
    Sphere(Eigen::Vector3d &center, float radius, Eigen::Vector3d &kamb, Eigen::Vector3d &kdif, Eigen::Vector3d &kspec) :
    c(center), r(radius){
        ka=kamb;
        kd=kdif;
        ks=kspec;
    }

    virtual HitRecord intersect(const Ray &ray);

private:
    Eigen::Vector3d c;
    double r;
};
}

#endif
