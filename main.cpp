#include <iostream>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "IOManager.h"

#include <GLFW/glfw3.h>
#include <sstream>

#include "Data/data.h"

char txt[256] = "Hello, World!";

void imgui_render() {
    float width = ImGui::CalcItemWidth();
    ImGui::Begin("Hello, world!", NULL, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoBackground);
    ImGui::SetWindowPos(ImVec2(0, 0));

    // set window full size of screen
    ImGui::SetWindowSize(ImVec2(width*2, 1000));

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

    // Switch between server and client
    ImGui::BeginGroup();
    ImGui::PushID("Server");
    ImGui::TextUnformatted("Type :");
    ImGui::SameLine();
    /*if (ImGui::RadioButton("##Server", &data::server)) {
        data::server = !data::server;
    }*/
    ImGui::Checkbox(data::server ? "Server" : "Client", &data::server);
    ImGui::PopID();
    ImGui::EndGroup();
//--------------------------------------------IP--------------------------------------------
    if (!data::server) {
        ImGui::BeginGroup();
        ImGui::PushID("IP");
        ImGui::TextUnformatted("IP");
        ImGui::SameLine();
        for (int i = 0; i < 4; i++) {
            ImGui::PushItemWidth(width / 4.0f);
            ImGui::PushID(i);
            bool invalid_octet = false;
            if (data::ip[i] > 255) {
                // Make values over 255 red, and when focus is lost reset it to 255.
                data::ip[i] = 255;
                invalid_octet = true;
                ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 0.0f, 0.0f, 1.0f));
            }
            if (data::ip[i] < 0) {
                // Make values below 0 yellow, and when focus is lost reset it to 0.
                data::ip[i] = 0;
                invalid_octet = true;
                ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 1.0f, 0.0f, 1.0f));
            }
            ImGui::InputInt("##v", &data::ip[i], 0, 0, ImGuiInputTextFlags_CharsDecimal);
            if (invalid_octet) {
                ImGui::PopStyleColor();
            }
            ImGui::SameLine();
            ImGui::PopID();
            ImGui::PopItemWidth();
        }
        ImGui::PopID();
        ImGui::EndGroup();
        ImGui::SameLine();
        if (ImGui::Button(data::connected ? "Disconnect" : "Connect")) {
            std::stringstream ip;
            ip << data::ip[0] << "." << data::ip[1] << "." << data::ip[2] << "." << data::ip[3];
            std::cout << "Connecting to " << ip.str() << std::endl;
            // toggle connected and change text of button to disconnect
            data::connected = !data::connected;
            data::onPc = !data::onPc;
        }
        // port fiead that can go from 0 to 65535
        ImGui::PushItemWidth(width / 2.9f);
        ImGui::InputInt("Port", &data::port);
        if (data::port > 65535) {
            data::port = 65535;
        }
        if (data::port < 0) {
            data::port = 0;
        }
    } else {
        ImGui::Text("Server Ip : %s", data::serverIp.c_str());
        ImGui::PushItemWidth(width / 2.9f);
        ImGui::InputInt("Port", &data::port);
    }
    //------------------------------------------------------------

    if (ImGui::Button("Open Popup to Change Text")) {
        ImGui::OpenPopup("change-text");
    }

    // Popup to change the text
    if (ImGui::BeginPopupModal("change-text", NULL, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse)) {
        // set pos centered
        ImGui::SetWindowPos(ImVec2(ImGui::GetIO().DisplaySize.x / 2 - ImGui::GetWindowSize().x / 2, ImGui::GetIO().DisplaySize.y / 2 - ImGui::GetWindowSize().y / 2));
        ImGui::InputText("Text", txt, ImGuiInputTextFlags_AutoSelectAll);
        if (ImGui::Button("Close")) {
            ImGui::CloseCurrentPopup();
        }
        ImGui::EndPopup();
    }

    ImGui::Text("winMouse Position: (%i,%i)", data::mouse.x, data::mouse.y);
    ImGui::Text("Delta: (%i,%i)", data::mouse.deltaX, data::mouse.deltaY);
    ImGui::Text("Scroll: (%i,%i)", data::mouse.wheel, data::mouse.deltaWheel);
    ImGui::Text("Left: %s", data::mouse.leftButton ? "true" : "false");
    ImGui::Text("Right: %s", data::mouse.rightButton ? "true" : "false");
    ImGui::Text("Middle: %s", data::mouse.middleButton ? "true" : "false");
    ImGui::Text("On PC: %s", data::onPc ? "true" : "false");
    ImGui::Text("Connected: %s", data::connected ? "true" : "false");

    ImGui::End();
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    IOManager::init();

    // simple glfw window with imgui
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(420, 450, "Hello World", NULL, NULL);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync
    //make window unresizable with flag GLFW_RESIZABLE
    glfwSetWindowAttrib(window, GLFW_RESIZABLE, GLFW_FALSE);
//    glfwSetWindowAttrib(window, GLFW_DECORATED, GLFW_FALSE);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        IOManager::update();
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

    std::cout << "Goodbye, World!" << std::endl;

    return 0;
}
