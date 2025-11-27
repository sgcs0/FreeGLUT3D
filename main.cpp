#include <stdlib.h>
#include <GL/glut.h>

class Engine {
private:
    int width;
    int height;
    int fps;
    float bgR, bgG, bgB;
    float rotX, rotY;

    static Engine* instance;

public:
    Engine() {
        width = 800;
        height = 600;
        fps = 60;
        bgR = 0.2f;
        bgG = 0.2f;
        bgB = 0.2f;
        rotX = 0.0f;
        rotY = 0.0f;
        instance = this;
    }

    void init(int argc, char** argv) {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
        glutInitWindowSize(width, height);
        glutCreateWindow("OpenGL 3D Engine");

        glutDisplayFunc(Engine::displayWrapper);
        glutReshapeFunc(Engine::reshapeWrapper);
        glutKeyboardFunc(Engine::keyboardWrapper);
        glutMouseFunc(Engine::mouseWrapper);
        glutTimerFunc(1000 / fps, Engine::timerWrapper, 0);

        glEnable(GL_DEPTH_TEST);
    }

    void run() {
        glutMainLoop();
    }

private:
    void render() {
        glClearColor(bgR, bgG, bgB, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glLoadIdentity();

        glRotatef(rotX, 1.0f, 0.0f, 0.0f);
        glRotatef(rotY, 0.0f, 1.0f, 0.0f);

        glColor3f(1.0f, 1.0f, 0.0f);
        glutWireTeapot(1.0);

        glutSwapBuffers();
    }

    void update() {
        glutTimerFunc(1000 / fps, Engine::timerWrapper, 0);
    }

    void reshape(int w, int h) {
        if (h == 0) h = 1;
        width = w;
        height = h;

        glViewport(0, 0, w, h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        float aspect = (float)w / (float)h;
        if (w >= h) {
            glOrtho(-2.0 * aspect, 2.0 * aspect, -2.0, 2.0, -10.0, 10.0);
        } else {
            glOrtho(-2.0, 2.0, -2.0 / aspect, 2.0 / aspect, -10.0, 10.0);
        }

        glMatrixMode(GL_MODELVIEW);
    }

    void handleKey(unsigned char key, int x, int y) {
        if (key == 27) exit(0);
        
        if (key == 'w') rotX -= 5.0f;
        if (key == 's') rotX += 5.0f;
        if (key == 'a') rotY -= 5.0f;
        if (key == 'd') rotY += 5.0f;

        if (key == 'r') { bgR = 0.5f; bgG = 0.0f; bgB = 0.0f; }
        if (key == 'g') { bgR = 0.0f; bgG = 0.5f; bgB = 0.0f; }
        if (key == 'b') { bgR = 0.0f; bgG = 0.0f; bgB = 0.5f; }
        
        glutPostRedisplay();
    }

    void handleMouse(int button, int state, int x, int y) {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            rotX = 0.0f;
            rotY = 0.0f;
            bgR = 0.2f; 
            bgG = 0.2f; 
            bgB = 0.2f;
        }
    }

    static void displayWrapper() {
        instance->render();
    }

    static void reshapeWrapper(int w, int h) {
        instance->reshape(w, h);
    }

    static void keyboardWrapper(unsigned char key, int x, int y) {
        instance->handleKey(key, x, y);
    }

    static void mouseWrapper(int button, int state, int x, int y) {
        instance->handleMouse(button, state, x, y);
    }

    static void timerWrapper(int value) {
        instance->update();
    }
};

Engine* Engine::instance = nullptr;

int main(int argc, char** argv) {
    Engine eng;
    eng.init(argc, argv);
    eng.run();
    return 0;
}