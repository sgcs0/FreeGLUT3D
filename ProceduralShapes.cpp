#include "ProceduralShapes.h"
#include <GL/glut.h>
#include <cmath>

ProceduralShapes::ProceduralShapes() {
    initialized = false;
}

void ProceduralShapes::generateData() {
    if (initialized) return;
    
    const int segments = 36;
    const float radius = 1.0f;
    const float height = 2.0f;
    const float halfH = height / 2.0f;

    // --- CONE ---
    coneSideVerts.push_back(0.0f); coneSideVerts.push_back(halfH); coneSideVerts.push_back(0.0f);
    for (int i = 0; i <= segments; i++) {
        float theta = (float)i / segments * 2.0f * 3.14159f;
        coneSideVerts.push_back(radius * cosf(theta));
        coneSideVerts.push_back(-halfH);
        coneSideVerts.push_back(radius * sinf(theta));
    }
    coneBaseVerts.push_back(0.0f); coneBaseVerts.push_back(-halfH); coneBaseVerts.push_back(0.0f);
    for (int i = segments; i >= 0; i--) {
        float theta = (float)i / segments * 2.0f * 3.14159f;
        coneBaseVerts.push_back(radius * cosf(theta));
        coneBaseVerts.push_back(-halfH);
        coneBaseVerts.push_back(radius * sinf(theta));
    }

    // --- CYLINDER ---
    for (int i = 0; i <= segments; i++) {
        float theta = (float)i / segments * 2.0f * 3.14159f;
        float x = radius * cosf(theta);
        float z = radius * sinf(theta);
        cylSideVerts.push_back(x); cylSideVerts.push_back(halfH); cylSideVerts.push_back(z);
        cylSideVerts.push_back(x); cylSideVerts.push_back(-halfH); cylSideVerts.push_back(z);
    }
    cylTopVerts.push_back(0.0f); cylTopVerts.push_back(halfH); cylTopVerts.push_back(0.0f);
    for (int i = 0; i <= segments; i++) {
        float theta = (float)i / segments * 2.0f * 3.14159f;
        cylTopVerts.push_back(radius * cosf(theta));
        cylTopVerts.push_back(halfH);
        cylTopVerts.push_back(radius * sinf(theta));
    }
    cylBotVerts.push_back(0.0f); cylBotVerts.push_back(-halfH); cylBotVerts.push_back(0.0f);
    for (int i = segments; i >= 0; i--) {
        float theta = (float)i / segments * 2.0f * 3.14159f;
        cylBotVerts.push_back(radius * cosf(theta));
        cylBotVerts.push_back(-halfH);
        cylBotVerts.push_back(radius * sinf(theta));
    }
    initialized = true;
}

void ProceduralShapes::DrawCylinder() {
    if (!initialized) generateData();
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, &cylSideVerts[0]);
    glDrawArrays(GL_QUAD_STRIP, 0, cylSideVerts.size()/3);
    glVertexPointer(3, GL_FLOAT, 0, &cylTopVerts[0]);
    glDrawArrays(GL_TRIANGLE_FAN, 0, cylTopVerts.size()/3);
    glVertexPointer(3, GL_FLOAT, 0, &cylBotVerts[0]);
    glDrawArrays(GL_TRIANGLE_FAN, 0, cylBotVerts.size()/3);
    glDisableClientState(GL_VERTEX_ARRAY);
}

void ProceduralShapes::DrawCone() {
    if (!initialized) generateData();
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, &coneSideVerts[0]);
    glDrawArrays(GL_TRIANGLE_FAN, 0, coneSideVerts.size()/3);
    glVertexPointer(3, GL_FLOAT, 0, &coneBaseVerts[0]);
    glDrawArrays(GL_TRIANGLE_FAN, 0, coneBaseVerts.size()/3);
    glDisableClientState(GL_VERTEX_ARRAY);
}

void ProceduralShapes::DrawPyramid() {
    static float PyramidVert[] = { 0,1.5,0, 1,-0.5,1, 1,-0.5,-1, -1,-0.5,-1, -1,-0.5,1, 1,-0.5,1 };
    static float PyramidBase[] = { 1,-0.5,1, 1,-0.5,-1, -1,-0.5,-1, -1,-0.5,1 };

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, PyramidVert);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 6);
    glVertexPointer(3, GL_FLOAT, 0, PyramidBase);
    glDrawArrays(GL_QUADS, 0, 4);
    glDisableClientState(GL_VERTEX_ARRAY);
}