//
// Created by cyber-toxo on 7/12/23.
//

#include "linuxMouse.h"

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>

#include <iostream>

using namespace sys;

Display *display;
Window root;
Window child;
XWindowAttributes window_attributes;

void sys::initializeMouseSys(){
    // x11 mouse initialization
    display = XOpenDisplay(nullptr);
    root = DefaultRootWindow(display);
}
int sys::getMouseXSys(){

    int x, y;
    XQueryPointer(display, root, &child, &child, &x, &y, &x, &y, reinterpret_cast<unsigned int *>(&window_attributes));
    return x;
}
int sys::getMouseYSys(){
    int x, y;
    XQueryPointer(display, root, &child, &child, &x, &y, &x, &y, reinterpret_cast<unsigned int *>(&window_attributes));

    return y;
}

void sys::setMousePositionSys(int x, int y){}
void sys::disableMouseSys(){}
void sys::enableMouseSys(){}

int sys::getDeltaMouseYSys(){
    return 0;
}
int sys::getDeltaMouseXSys(){
    return 0;
}

std::pair<int, int> sys::getMousePositionSys() {
    std::pair<int, int> pos;
    XQueryPointer(display, root, &child, &child, &pos.first, &pos.second, &pos.first, &pos.second, reinterpret_cast<unsigned int *>(&window_attributes));
    return pos;
}
