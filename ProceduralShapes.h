#ifndef PROCEDURALSHAPES_H
#define PROCEDURALSHAPES_H

#include <vector>

class ProceduralShapes {
private:
    std::vector<float> coneSideVerts;
    std::vector<float> coneBaseVerts;
    std::vector<float> cylSideVerts;
    std::vector<float> cylTopVerts;
    std::vector<float> cylBotVerts;
    bool initialized;

    void generateData();

public:
    ProceduralShapes();
    void DrawCylinder();
    void DrawCone();
    void DrawPyramid();
};

#endif