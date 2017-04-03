//
//  Triangle.cpp
//  
//
//  Created by SequenceOne on 27/07/16.
//
//

#include <stdio.h>
#include "Triangle.h"
#include<limits>
using namespace Raytracer148;
using namespace Eigen;
using namespace std;

HitRecord Triangle::intersect(const Ray &ray){
    HitRecord result;
    result.t=-1;
    
//    Vector3d edge1, edge2;
//    Vector3d P,Q,T;
//    float det, invDet, u,v;
//    float t;
//    
//    edge1=b-a;
//    edge2=c-a;
//    P=ray.direction.cross(edge2);
//    det=edge1.dot(P);
//    
//    if(det>-numeric_limits<double>::epsilon() && det< numeric_limits<double>::epsilon())
//        return result;
//    invDet=1.f/det;
//    
//    T=ray.origin-a;
//    u=T.dot(P)*invDet;
//    if(u<0.f || u>1.f)
//        return result;
//    
//    Q=T.cross(edge1);
//    v=ray.direction.dot(Q)*invDet;
//    if(v<0.f || v+u>1.f)
//        return result;
//    
//    t=edge2.dot(Q)*invDet;
//    
//    if(t>numeric_limits<double>::epsilon()){
//        result.t=t;
//        result.position=ray.origin+result.t*ray.direction;
//        result.normal=-edge1.cross(edge2);
//        return result;
//    }
//        
//    return result;
    
    
    Matrix3d MatA,MatBheta,MatGama,MatT;
    double t, bheta, gamma;
    
    MatA(0,0) = a[0]-b[0];
    MatA(0,1) = a[0]-c[0] ;
    MatA(0,2) = ray.direction[0];
    MatA(1,0) = a[1]-b[1];
    MatA(1,1) = a[1]-c[1] ;
    MatA(1,2) = ray.direction[1];
    MatA(2,0) = a[2]-b[2];
    MatA(2,1) = a[2]-c[2] ;
    MatA(2,2) = ray.direction[2];
    
    MatBheta(0,0) = a[0]-ray.origin[0];
    MatBheta(0,1) = a[0]-c[0] ;
    MatBheta(0,2) = ray.direction[0];
    MatBheta(1,0) = a[1]-ray.origin[1];
    MatBheta(1,1) = a[1]-c[1] ;
    MatBheta(1,2) = ray.direction[1];
    MatBheta(2,0) = a[2]-ray.origin[2];
    MatBheta(2,1) = a[2]-c[2] ;
    MatBheta(2,2) = ray.direction[2];
    
    MatGama(0,0) = a[0]-b[0];
    MatGama(0,1) = a[0]-ray.origin[0];
    MatGama(0,2) = ray.direction[0];
    MatGama(1,0) = a[1]-b[1];
    MatGama(1,1) = a[1]-ray.origin[1];
    MatGama(1,2) = ray.direction[1];
    MatGama(2,0) = a[2]-b[2];
    MatGama(2,1) = a[2]-ray.origin[2];
    MatGama(2,2) = ray.direction[2];
    
    MatT(0,0) = a[0]-b[0];
    MatT(0,1) = a[0]-c[0];
    MatT(0,2) = a[0]-ray.origin[0];
    MatT(1,0) = a[1]-b[1];
    MatT(1,1) = a[1]-c[1];
    MatT(1,2) = a[1]-ray.origin[1];
    MatT(2,0) = a[2]-b[2];
    MatT(2,1) = a[2]-c[2];
    MatT(2,2) = a[2]-ray.origin[2];
    
    
    t=MatT.determinant()/MatA.determinant();
    bheta=MatBheta.determinant()/MatA.determinant();
    gamma=MatGama.determinant()/MatA.determinant();
    
    if(t<0){
        return result;
    }
    if(gamma<0 || gamma>1){
        return result;
    }
    if(bheta<0 || bheta>(1-gamma)){
        return result;
    }

    
    result.t=t;
    result.position=ray.origin+result.t*ray.direction;
    result.normal=-(b-a).cross(c-a);
    result.sh=this;
    
    return result;
    
}
