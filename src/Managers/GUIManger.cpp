//
// Created by trist on 2023-07-13.
//

#include "GUIManger.h"

#include <GLFW/glfw3.h>

#include <iostream>
#include <thread>

GUIManger::GUIManger(bool *pBoolean) {
    // set running to be the same as the boolean passed in so if it changes in main it changes here
    running = pBoolean;
    GLFWInit();
    ImGuiInit();
}

GUIManger::~GUIManger() {
    GLFWDestory();
}

void GUIManger::GLFWInit() {
    // simple glfw window
    glfwInit();
    window = glfwCreateWindow(420, 450, "Hello World", NULL, NULL);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync
    //make window unresizable with flag GLFW_RESIZABLE
    glfwSetWindowAttrib(window, GLFW_RESIZABLE, GLFW_FALSE);
}

void GUIManger::ImGuiInit() {

}

void GUIManger::GLFWDestory() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

void GUIManger::update() {
    if (running){
        if (!glfwWindowShouldClose(window)) {
            render();
        } else {
            GLFWDestory();
            *running = false;
        }
    }
}

void GUIManger::render() {
    glfwPollEvents();
    glfwSwapBuffers(window);
}
