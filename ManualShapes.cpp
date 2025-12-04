#include "ManualShapes.h"
#include <GL/glut.h>

void ManualShapes::DrawIndexedCube() {
    // PDF Figure 8: Vertices
    static const float cube_vert[] = {
        -1.0f, -1.0f, 1.0f,   1.0f, -1.0f, 1.0f,  -1.0f,  1.0f, 1.0f,   1.0f,  1.0f, 1.0f,
         1.0f, -1.0f,  1.0f,  1.0f, -1.0f, -1.0f,  1.0f,  1.0f,  1.0f,  1.0f,  1.0f, -1.0f,
         1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f,  1.0f,  1.0f, -1.0f, -1.0f,  1.0f, -1.0f,
        -1.0f, -1.0f, -1.0f, -1.0f, -1.0f,  1.0f, -1.0f,  1.0f, -1.0f, -1.0f,  1.0f,  1.0f,
        -1.0f,  1.0f,  1.0f,   1.0f,  1.0f,  1.0f, -1.0f,  1.0f, -1.0f,   1.0f,  1.0f, -1.0f,
        -1.0f, -1.0f, -1.0f,   1.0f, -1.0f, -1.0f, -1.0f, -1.0f,  1.0f,   1.0f, -1.0f,  1.0f
    };
    // PDF Figure 8: Normals
    static const float cube_norm[] = {
        0,0,1, 0,0,1, 0,0,1, 0,0,1,   1,0,0, 1,0,0, 1,0,0, 1,0,0,
        0,0,-1, 0,0,-1, 0,0,-1, 0,0,-1, -1,0,0, -1,0,0, -1,0,0, -1,0,0,
        0,1,0, 0,1,0, 0,1,0, 0,1,0,   0,-1,0, 0,-1,0, 0,-1,0, 0,-1,0
    };
    // PDF Figure 8: Colors
    static const float cube_cols[] = {
        1.0, 0.3, 0.3, 1.0, 0.3, 0.3, 1.0, 0.3, 0.3, 1.0, 0.3, 0.3,
        1.0, 1.0, 0.3, 1.0, 1.0, 0.3, 1.0, 1.0, 0.3, 1.0, 1.0, 0.3,
        0.3, 1.0, 0.3, 0.3, 1.0, 0.3, 0.3, 1.0, 0.3, 0.3, 1.0, 0.3,
        0.3, 1.0, 1.0, 0.3, 1.0, 1.0, 0.3, 1.0, 1.0, 0.3, 1.0, 1.0,
        0.3, 0.3, 1.0, 0.3, 0.3, 1.0, 0.3, 0.3, 1.0, 0.3, 0.3, 1.0,
        1.0, 0.3, 1.0, 1.0, 0.3, 1.0, 1.0, 0.3, 1.0, 1.0, 0.3, 1.0
    };
    // PDF Figure 9: Indices
    static const unsigned char cube_ind[] = {
        0, 1, 2, 2, 1, 3,  4, 5, 6, 6, 5, 7,  8, 9, 10, 10, 9, 11,
        12, 13, 14, 14, 13, 15, 16, 17, 18, 18, 17, 19, 20, 21, 22, 22, 21, 23
    };

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, cube_vert);
    glEnableClientState(GL_NORMAL_ARRAY);
    glNormalPointer(GL_FLOAT, 0, cube_norm);
    glEnableClientState(GL_COLOR_ARRAY);
    glColorPointer(3, GL_FLOAT, 0, cube_cols);
    glDrawElements(GL_TRIANGLES, sizeof(cube_ind), GL_UNSIGNED_BYTE, cube_ind);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
}

void ManualShapes::DrawPrimitive(int mode) {
    glEnableClientState(GL_VERTEX_ARRAY);

    // PDF Fig 11: Points
    static float PointVert[] = { -4,0,0, 0,4,0, 5,1,0, 0,0,0 };
    // PDF Fig 12: Lines
    static float LineVert[] = { -4,0,0, 0,4,0, 5,1,0, 0,0,0 }; 
    // PDF Fig 13: Line Strip/Loop
    static float StripVert[] = { -4,0,0, 0,4,0, 5,1,0 }; 
    // PDF Fig 14: Triangles
    static float TriVert[] = { -4,0,0, 0,4,0, -1,1,0, 5,1,0, 2,4,0, 0,0,0 };
    // PDF Fig 15: Triangle Strip/Fan
    static float FanVert[] = { 0,0,0, 2,2,0, 2,-1,0, 0,-2,0, -2,-1,0, -2,2,0 };
    // PDF Fig 16: Quads
    static float QuadVert[] = { -2,0,0, -2,4,0, 4,4,0, 4,0,0 };

    switch(mode) {
        case 1: // Points
            glVertexPointer(3, GL_FLOAT, 0, PointVert);
            glPointSize(5.0f);
            glDrawArrays(GL_POINTS, 0, 4);
            break;
        case 2: // Line (Single segment per your request)
            glVertexPointer(3, GL_FLOAT, 0, LineVert);
            glLineWidth(5.0f);
            glDrawArrays(GL_LINES, 0, 2); 
            break;
        case 3: // Line Strip
            glVertexPointer(3, GL_FLOAT, 0, StripVert);
            glLineWidth(3.0f);
            glDrawArrays(GL_LINE_STRIP, 0, 3);
            break;
        case 4: // Line Loop
            glVertexPointer(3, GL_FLOAT, 0, StripVert);
            glLineWidth(3.0f);
            glDrawArrays(GL_LINE_LOOP, 0, 3);
            break;
        case 5: // Triangles
            glVertexPointer(3, GL_FLOAT, 0, TriVert);
            glDrawArrays(GL_TRIANGLES, 0, 6);
            break;
        case 6: // Triangle Strip
            glVertexPointer(3, GL_FLOAT, 0, FanVert); // Reusing Fan/Strip data from Fig 15
            glDrawArrays(GL_TRIANGLE_STRIP, 0, 6);
            break;
        case 7: // Triangle Fan
            glVertexPointer(3, GL_FLOAT, 0, FanVert);
            glDrawArrays(GL_TRIANGLE_FAN, 0, 6);
            break;
        case 8: // Quads
            glVertexPointer(3, GL_FLOAT, 0, QuadVert);
            glDrawArrays(GL_QUADS, 0, 4);
            break;
    }
    glDisableClientState(GL_VERTEX_ARRAY);
}