#include "Engine.h"

int main(int argc, char** argv) {
    Engine app;
    app.init(argc, argv);
    app.run();
    return 0;
}