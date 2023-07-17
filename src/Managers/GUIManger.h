//
// Created by trist on 2023-07-13.
//

#ifndef KOUSECPP_GUIMANGER_H
#define KOUSECPP_GUIMANGER_H

#include <thread>
#include <atomic>

#include <GLFW/glfw3.h>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

class GUIManger {
public:
    GUIManger(bool *pBoolean);
    ~GUIManger();
    void update();

private:
    void GLFWInit();
    void ImGuiInit();
    void GLFWDestory();
    void render();

    GLFWwindow* window;
    bool* running;
};


#endif //KOUSECPP_GUIMANGER_H
