#ifndef MANUALSHAPES_H
#define MANUALSHAPES_H

class ManualShapes {
public:
    // Exercise 2: Indexed Cube (Strict PDF implementation)
    void DrawIndexedCube(); 
    
    // Exercise 1: Static Primitives from Section 4
    // mode: 1=Points, 2=Line, 3=LineStrip, 4=LineLoop, 
    //       5=Triangles, 6=TriStrip, 7=TriFan, 8=Quads
    void DrawPrimitive(int mode); 
};

#endif