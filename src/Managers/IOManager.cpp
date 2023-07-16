//
// Created by trist on 2023-06-04.
//

#include "IOManager.h"

#include <iostream>
#include "../Data/data.h"

#ifdef _WIN32
#include "../crossplatform/Windows/winMouse.h"
#elif __linux__
#include "Linux/linuxMouse.h"
#endif

IOManager::IOManager() {
    sys::initializeMouseSys();
}

IOManager::~IOManager() {
}



void IOManager::update() {
    std::pair<int,int> pos = sys::getMousePositionSys();
    mouseX = pos.first;
    mouseY = pos.second;

    std::cout << "x: " << mouseX << " y: " << mouseY << std::endl;

    if (data::onPc) {
        sys::enableMouseSys();
    } else {
        sys::disableMouseSys();
    }
}

void IOManager::setMousePosition(int x, int y) {
    sys::setMousePositionSys(x, y);
}

int IOManager::getMouseX() {
    return mouseX;
}

int IOManager::getMouseY() {
    return mouseY;
}

int IOManager::getMouseWheel() {
    return mouseWheel;
}
