//
// Created by trist on 2023-06-04.
//

#include "IOManager.h"

#include <iostream>
#include "Data/data.h"

#ifdef _WIN32
#include "Windows/winMouse.h"
#else
std::cout << "Not running on Windows" << std::endl;
#endif

IOManager::IOManager() {
}

IOManager::~IOManager() {
}



void IOManager::update() {
    data::mouse.x = sys::getMouseXSys();
    data::mouse.y = sys::getMouseYSys();
    data::mouse.deltaX = sys::getDeltaMouseXSys();
    data::mouse.deltaY = sys::getDeltaMouseYSys();

    if (data::onPc) {
        sys::enableMouseSys();
    } else {
        sys::disableMouseSys();
    }
}

void IOManager::setMousePosition(int x, int y) {
    sys::setMousePositionSys(x, y);
}

void IOManager::disableKeyboard() {
}

void IOManager::enableKeyboard() {
}

int IOManager::getMouseX() {
    return sys::getMouseXSys();
}

int IOManager::getMouseY() {
    return sys::getMouseYSys();
}

void IOManager::init() {
    sys::initializeMouseSys();
}
