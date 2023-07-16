#include <iostream>

#include <GLFW/glfw3.h>
#include <sstream>
#include <thread>

#include "Managers/GUIManger.h"
#include "Managers/IOManager.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    bool running = true;

    GUIManger gui;
    IOManager io;

    while (running){
        gui.update();
        io.update();
    }

    std::cout << "Goodbye, World!" << std::endl;

    return 0;
}
