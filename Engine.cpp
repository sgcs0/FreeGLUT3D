#include "Engine.h"

Engine* Engine::instance = nullptr;

Engine::Engine() {
    width = 800;
    height = 600;
    rotation = 0.0f;
    instance = this;
}

void Engine::init(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutCreateWindow("Simple Shapes");

    glutDisplayFunc(displayWrapper);
    glutReshapeFunc(reshapeWrapper);
    glutTimerFunc(16, timerWrapper, 0);

    glEnable(GL_DEPTH_TEST);
}

void Engine::run() {
    glutMainLoop();
}

void Engine::render() {
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -5.0f);
    glRotatef(rotation, 0.0f, 1.0f, 0.0f);

    glColor3f(1.0f, 0.0f, 0.0f);
    shapes.DrawCube(-1.5f, 0.0f, 0.0f, 1.0f);

    glColor3f(0.0f, 1.0f, 0.0f);
    shapes.DrawSphere(1.5f, 0.0f, 0.0f, 0.7f);

    glColor3f(1.0f, 1.0f, 0.0f);
    shapes.DrawTeapot(0.0f, 1.2f, 0.0f, 0.6f);

    glColor3f(0.0f, 0.5f, 1.0f);
    shapes.DrawCone(0.0f, -1.2f, 0.0f, 0.5f, 1.0f);

    glutSwapBuffers();
}

void Engine::update() {
    rotation += 1.0f;
    glutTimerFunc(16, timerWrapper, 0);
}

void Engine::reshape(int w, int h) {
    if (h == 0) h = 1;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float aspect = (float)w / h;
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

void Engine::displayWrapper() { instance->render(); }
void Engine::reshapeWrapper(int w, int h) { instance->reshape(w, h); }
void Engine::timerWrapper(int v) { instance->update(); }