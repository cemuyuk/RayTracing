#include <iostream>
#include "Image.h"
#include "Scene.h"
#include "Sphere.h"
#include "Triangle.h"
#include "Shader.h"
#include <cmath>

// GLM Mathematics
#define GLM_FORCE_RADIANS // force everything in radian
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace std;
using namespace Raytracer148;
using namespace Eigen;

int main() {
    Image im(400, 400);

    Scene scene;

    Vector3d center, kAmb, kDif, kSpec;
    //Sphere1
    kAmb[0]=0.1;
    kAmb[1]=0;
    kAmb[2]=0;
    
    kDif[0]=0.5;
    kDif[1]=0;
    kDif[2]=0;
    
    kSpec[0]=1.0;
    kSpec[1]=1.0;
    kSpec[2]=1.0;
    
    
    //SPHERES
    center[0] = 0;
    center[1] = 0;
    center[2] = 4;
    scene.addShape(new Sphere(center, 2, kAmb, kDif, kSpec));

    
    //Sphere2
    kAmb[0]=0;
    kAmb[1]=0.1;
    kAmb[2]=0;
    
    kDif[0]=0;
    kDif[1]=0.5;
    kDif[2]=0;
    

    
    center[0] = .6;
    center[1] = -0.1;
    center[2] = 1.7;
    scene.addShape(new Sphere(center, .5, kAmb, kDif, kSpec));

    
    //Sphere3
    kAmb[0]=0;
    kAmb[1]=0;
    kAmb[2]=.1;
    
    kDif[0]=0;
    kDif[1]=0;
    kDif[2]=0.5;
    
    center[0] = 1.10;
    center[1] = 1.10;
    center[2] = 2.2;
    scene.addShape(new Sphere(center, .5,kAmb,kDif,kSpec));
    
    
    //TRIANGLES
//    Vector3d v0,v1,v2,v3,v4,v5;
//    v0[0]=-0.5;
//    v0[1]=0;
//    v0[2]=.5;
//    
//    v1[0]=0.5;
//    v1[1]=0;
//    v1[2]=1.5;
//    
//    v2[0]=0;
//    v2[1]=1.0;
//    v2[2]=1;
//
//    scene.addShape(new Triangle(v0,v1,v2,kAmb,kDif,kSpec));
//    
//    v3[0]=0;
//    v3[1]=.0;
//    v3[2]=0.1;
//    
//    v4[0]=0.1;
//    v4[1]=0.1;
//    v4[2]=.2;
//    
//    v5[0]=0;
//    v5[1]=.2;
//    v5[2]=.2;
//    
//    scene.addShape(new Triangle(v3,v4,v5,kAmb,kDif,kSpec));
    
    
    scene.render(im);

    im.writePNG("test.png");

    return 0;
}
