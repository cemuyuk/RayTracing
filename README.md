# RayTracing
Ray Tracing implemented in C

 Image.h/cpp: Provides simple functionality for writing .png images; requires libpng to
compile.
 Scene.h/cpp: Stores the objects in a scene and performs basic ray tracing.
 Shape.h/cpp: An abstract class for representing a shape; also defines Ray and HitRecord
structs.
 Sphere.h/cpp: An example child class of Shape.
 main.cpp: The entry point for the program. Sets up a scene, initiates ray tracing, and saves
the output.

The final ray tracer has shading, shadowing, reflecting and antialiasing included. You need a makefile and some libraries including eigen to run it. You can find them if you check the includes in header files.
