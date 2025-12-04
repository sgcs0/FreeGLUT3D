#include "Engine.h"

// --- ADDED GLM INCLUDES FOR LAB 07 COMPLIANCE ---
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Engine* Engine::instance = nullptr;

Engine::Engine() {
    width = 800;
    height = 600;
    rotX = 0.0f; rotY = 0.0f; rotZ = 0.0f;
    bgR = 0.2f; bgG = 0.2f; bgB = 0.2f;
    currentMode = 2; 
    orthoMode = false; 
    instance = this;
}

void Engine::init(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutCreateWindow("3D");

    glutDisplayFunc(displayWrapper);
    glutReshapeFunc(reshapeWrapper);
    glutMouseFunc(mouseWrapper);
    glutKeyboardFunc(keyboardWrapper);
    glutTimerFunc(16, timerWrapper, 0);

    glEnable(GL_DEPTH_TEST);

printf("--- STEROWANIE ---\n");
    printf("[W/S] Pochylenie | [A/D] Odchylenie | [Q/E] Przechylenie \n");
    printf("[P] Przelacz rzutowanie (Perspektywiczne/Ortogonalne - GLM)\n");
    printf("[Przyciski myszki] Kolor tla\n\n");
    printf("--- GLOWNE OBIEKTY ---\n");
    printf("[1] Linia (Recznie)\n");
    printf("[2] Szescian indeksowany (Recznie)\n");
    printf("[3] Czworokat (Recznie)\n");
    printf("[4] Walec (Proceduralny)\n");
    printf("[5] Stozek (Proceduralny)\n");
    printf("[6] Ostroslup (Proceduralny)\n");
    printf("[7] Punkty, [8] Trojkaty, [9] Lamana, [0] Wachlarz\n");
}

void Engine::run() {
    glutMainLoop();
}

void Engine::render() {
    glClearColor(bgR, bgG, bgB, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Camera setup
    if (orthoMode) {
        // No Z-translation needed for Ortho usually, just scaling to see the objects
        glScalef(0.5f, 0.5f, 0.5f); 
    } else {
        glTranslatef(0.0f, 0.0f, -6.0f);
    }
    
    // Rotation
    glRotatef(rotX, 1.0f, 0.0f, 0.0f);
    glRotatef(rotY, 0.0f, 1.0f, 0.0f);
    glRotatef(rotZ, 0.0f, 0.0f, 1.0f);

    switch (currentMode) {
        case 1: glColor3f(1,1,0); manualShapes.DrawPrimitive(2); break;
        case 2: manualShapes.DrawIndexedCube(); break;
        case 3: glColor3f(0,1,1); manualShapes.DrawPrimitive(8); break;
        case 4: glColor3f(1,0,1); proceduralShapes.DrawCylinder(); break;
        case 5: glColor3f(0,0.5,1); proceduralShapes.DrawCone(); break;
        case 6: glColor3f(1,0.5,0); proceduralShapes.DrawPyramid(); break;
        case 7: glColor3f(1,1,1); manualShapes.DrawPrimitive(1); break;
        case 8: glColor3f(0,1,0); manualShapes.DrawPrimitive(5); break;
        case 9: glColor3f(1,0,0); manualShapes.DrawPrimitive(3); break;
        case 0: glColor3f(0.5,0,0.5); manualShapes.DrawPrimitive(7); break;
    }

    glutSwapBuffers();
}

void Engine::update() {
    glutPostRedisplay();
    glutTimerFunc(16, timerWrapper, 0);
}

// --- UPDATED FOR GLM COMPLIANCE (Lab 07 Section 4 & 5) ---
void Engine::reshape(int w, int h) {
    if (h == 0) h = 1;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    float aspect = (float)w / h;
    glm::mat4 projection; // Matrix to store the GLM result

    if (orthoMode) {
        // Lab 07 Section 5.1: Use glm::ortho 
        if (w >= h) {
            projection = glm::ortho(-3.0f * aspect, 3.0f * aspect, -3.0f, 3.0f, -10.0f, 10.0f);
        } else {
            projection = glm::ortho(-3.0f, 3.0f, -3.0f / aspect, 3.0f / aspect, -10.0f, 10.0f);
        }
    } else {
        // Lab 07 Section 5.2: Use glm::perspective 
        // Note: GLM takes FOV in Radians, unlike gluPerspective which takes Degrees.
        // PDF suggests 60 degrees, previous code used 45. Using 45 here.
        projection = glm::perspective(glm::radians(45.0f), aspect, 0.1f, 100.0f);
    }
    
    // Load the GLM matrix into OpenGL
    glLoadMatrixf(glm::value_ptr(projection));
    
    glMatrixMode(GL_MODELVIEW);
}

void Engine::handleMouse(int button, int state, int x, int y) {
    if (state == GLUT_DOWN) {
        if (button == GLUT_LEFT_BUTTON) { bgR=0.8f; bgG=0.1f; bgB=0.1f; }
        else if (button == GLUT_MIDDLE_BUTTON) { bgR=0.1f; bgG=0.8f; bgB=0.1f; }
        else if (button == GLUT_RIGHT_BUTTON) { bgR=0.1f; bgG=0.1f; bgB=0.8f; }
    }
}

void Engine::handleKeyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'w': rotX -= 5.0f; break;
        case 's': rotX += 5.0f; break;
        case 'a': rotY -= 5.0f; break;
        case 'd': rotY += 5.0f; break;
        case 'q': rotZ -= 5.0f; break; 
        case 'e': rotZ += 5.0f; break; 
        case 'p': orthoMode = !orthoMode; reshape(width, height); break;
            
        case '1': currentMode = 1; break; 
        case '2': currentMode = 2; break; 
        case '3': currentMode = 3; break; 
        case '4': currentMode = 4; break; 
        case '5': currentMode = 5; break; 
        case '6': currentMode = 6; break;
        case '7': currentMode = 7; break;
        case '8': currentMode = 8; break;
        case '9': currentMode = 9; break;
        case '0': currentMode = 0; break;
    }
}

void Engine::displayWrapper() { instance->render(); }
void Engine::reshapeWrapper(int w, int h) { instance->reshape(w, h); }
void Engine::mouseWrapper(int b, int s, int x, int y) { instance->handleMouse(b, s, x, y); }
void Engine::keyboardWrapper(unsigned char k, int x, int y) { instance->handleKeyboard(k, x, y); }
void Engine::timerWrapper(int v) { instance->update(); }