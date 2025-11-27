#include "SimpleShapes.h"
#include <GL/glut.h>

void SimpleShapes::DrawCube(float x, float y, float z, float size) {
    glPushMatrix();
    glTranslatef(x, y, z);
    glutWireCube(size);
    glPopMatrix();
}

void SimpleShapes::DrawSphere(float x, float y, float z, float radius) {
    glPushMatrix();
    glTranslatef(x, y, z);
    glutWireSphere(radius, 16, 16);
    glPopMatrix();
}

void SimpleShapes::DrawCone(float x, float y, float z, float base, float height) {
    glPushMatrix();
    glTranslatef(x, y, z);
    glutWireCone(base, height, 16, 16);
    glPopMatrix();
}

void SimpleShapes::DrawTeapot(float x, float y, float z, float size) {
    glPushMatrix();
    glTranslatef(x, y, z);
    glutWireTeapot(size);
    glPopMatrix();
}

void SimpleShapes::DrawTorus(float x, float y, float z, float innerRadius, float outerRadius) {
    glPushMatrix();
    glTranslatef(x, y, z);
    glutWireTorus(innerRadius, outerRadius, 12, 24);
    glPopMatrix();
}