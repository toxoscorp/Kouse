#include <iostream>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include <GLFW/glfw3.h>
#include <sstream>

char txt[256] = "Hello, World!";

double last_x = 0;
double last_y = 0;

void test_mouse() {
    // get mouse relative position even if window is not focus and print it to console
    double x, y;
    glfwGetCursorPos(glfwGetCurrentContext(), &x, &y);
    std::stringstream ss;
    ss << "Mouse Position: " << x - last_x << ", " << y - last_y;
    if ((x-last_x != 0 || y-last_y != 0) && (last_x < 10000 || last_y < 10000)) {
        std::cout << ss.str() << std::endl;
    }
    last_x = x;
    last_y = y;
}

void imgui_render() {
    ImGui::Begin("Hello, world!", NULL, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoBackground);
    ImGui::SetWindowPos(ImVec2(0, 0));

    // Button that changes the color of the text
    static bool change_color = false;

    if (change_color) {
        ImGui::TextColored(ImVec4(0, 1, 0, 1), "%s", txt);
    } else {
        ImGui::TextColored(ImVec4(1, 0, 1, 1), "%s", txt);
    }
    if (ImGui::Button("Change Color")) {
        change_color = !change_color;
    }

    if (ImGui::Button("Open Popup to Change Text")) {
        ImGui::OpenPopup("change-text");
    }

    // Popup to change the text
    if (ImGui::BeginPopupModal("change-text", NULL, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse)) {
        ImGui::InputText("Text", txt, ImGuiInputTextFlags_AutoSelectAll);
        if (ImGui::Button("Close")) {
            ImGui::CloseCurrentPopup();
        }
        ImGui::EndPopup();
    }
    ImGui::End();
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    // simple glfw window with imgui
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(1280, 720, "Hello World", NULL, NULL);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    while (!glfwWindowShouldClose(window))
    {
        test_mouse();
        glfwPollEvents();
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        imgui_render();

        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwMakeContextCurrent(window);
        glfwSwapBuffers(window);
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
