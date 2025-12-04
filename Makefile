all:
	g++ main.cpp Engine.cpp SimpleShapes.cpp ManualShapes.cpp ProceduralShapes.cpp -o main.exe -I"freeglut\include" -L"freeglut\lib\x64" -lfreeglut -lopengl32 -lglu32 -g -Wall -I.
