//
//  Triangle.h
//  
//
//  Created by SequenceOne on 27/07/16.
//
//

#ifndef Triangle_h
#define Triangle_h

#include "Shape.h"

namespace Raytracer148 {
    class Triangle : public Shape {
    public:
        Triangle(Eigen::Vector3d &vertex0, Eigen::Vector3d &vertex1, Eigen::Vector3d &vertex2, Eigen::Vector3d &kamb, Eigen::Vector3d &kdif, Eigen::Vector3d &kspec) :
            a(vertex0),
            b(vertex1),
            c(vertex2)
        {
            ka=kamb;
            kd=kdif;
            ks=kspec;
        }
        
        virtual HitRecord intersect (const Ray &ray);
        
    private:
        Eigen::Vector3d a;
        Eigen::Vector3d b;
        Eigen::Vector3d c;
        
    };
}


#endif /* Triangle_h */
