all:
	g++ main.cpp -o main.exe -I"C:\Dev\freeglut\include" -L"C:\Dev\freeglut\lib\x64" -lfreeglut -lopengl32 -lglu32 -g -Wall