all:
	g++ main.cpp Engine.cpp SimpleShapes.cpp -o main.exe -I"freeglut\include" -L"freeglut\lib\x64" -lfreeglut -lopengl32 -lglu32 -g -Wall
	copy "freeglut\bin\x64\freeglut.dll" .