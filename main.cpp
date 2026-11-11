#define STB_IMAGE_IMPLEMENTATION
#include "main.h"

int main() {
    Engine engine;
    engine.init();
    engine.run();
    engine.end();
    return 1;
}