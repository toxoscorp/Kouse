cmake_minimum_required(VERSION 3.0)
project(KouseCPP)

# DOWNLOAD SUBMODULES #
#find_package(Git QUIET)
#if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
#    # Update submodules as needed
#    option(GIT_SUBMODULE "Check submodules during build" ON)
#    if(GIT_SUBMODULE)
#        message(STATUS "Submodule update")
#        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
#                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
#                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
#        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
#            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
#        endif()
#    endif()
#endif()

set(CMAKE_CXX_STANDARD 23)

set(IMGUI_SRC externals/imgui/imgui.cpp
        externals/imgui/imgui_demo.cpp
        externals/imgui/imgui_draw.cpp
        externals/imgui/imgui_widgets.cpp
        externals/imgui/imgui_tables.cpp
        externals/imgui/backends/imgui_impl_glfw.cpp
        externals/imgui/backends/imgui_impl_opengl3.cpp configManager.cpp configManager.h Windows/winMouse.cpp Windows/winMouse.h Data/data.h Data/data.cpp Networking/Server.cpp Networking/Server.h Networking/Client.cpp Networking/Client.h)

add_executable(KouseCPP main.cpp ${IMGUI_SRC} network.cpp network.h IOManager.cpp IOManager.h Windows/winMouse.h Data/Mouse.h)


add_subdirectory(externals/glfw)
add_subdirectory(externals/enet)

target_include_directories(KouseCPP
        PUBLIC externals/glfw/include
        PUBLIC externals/imgui
        PUBLIC externals/imgui/backends
        PUBLIC externals/enet/include
        )

find_package(OpenGL REQUIRED)

if (OPENGL_FOUND)
    message("opengl found")
    message("include dir: ${OPENGL_INCLUDE_DIR}")
    message("link libraries: ${OPENGL_gl_LIBRARY}")
else (OPENGL_FOUND)
    message("opengl not found")
endif()

target_link_libraries(KouseCPP glfw ${OPENGL_gl_LIBRARY} enet)

if(WIN32)
    target_link_libraries(KouseCPP kernel32)
endif()