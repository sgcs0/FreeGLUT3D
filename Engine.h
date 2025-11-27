#ifndef ENGINE_H
#define ENGINE_H

#include <stdlib.h>
#include <GL/glut.h>
#include "SimpleShapes.h"

class Engine {
private:
    int width, height;
    float rotation;
    SimpleShapes shapes;
    static Engine* instance;

public:
    Engine();
    void init(int argc, char** argv);
    void run();

private:
    void render();
    void update();
    void reshape(int w, int h);
    
    static void displayWrapper();
    static void reshapeWrapper(int w, int h);
    static void timerWrapper(int value);
};

#endif