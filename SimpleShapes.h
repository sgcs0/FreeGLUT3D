#ifndef SIMPLESHAPES_H
#define SIMPLESHAPES_H

class SimpleShapes {
public:
    void DrawCube(float x, float y, float z, float size);
    void DrawSphere(float x, float y, float z, float radius);
    void DrawCone(float x, float y, float z, float base, float height);
    void DrawTeapot(float x, float y, float z, float size);
    void DrawTorus(float x, float y, float z, float innerRadius, float outerRadius);
};

#endif