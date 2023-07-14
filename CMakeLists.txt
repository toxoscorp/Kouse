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

# IMGUI source
set(IMGUI_SRC externals/imgui/imgui.cpp
        externals/imgui/imgui_demo.cpp
        externals/imgui/imgui_draw.cpp
        externals/imgui/imgui_widgets.cpp
        externals/imgui/imgui_tables.cpp
        externals/imgui/backends/imgui_impl_glfw.cpp
        externals/imgui/backends/imgui_impl_opengl3.cpp src/Data/configManager.cpp src/Data/configManager.h)

# Crossplatform source
if (WIN32)
    set(IO src/crossplatform/Windows/winMouse.cpp src/crossplatform/Windows/winMouse.h)
elseif (UNIX)
    set(IO src/crossplatform/Linux/linuxMouse.cpp src/crossplatform/Linux/linuxMouse.h)
elseif (APPLE)
    set(IO Mac/macMouse.cpp Mac/macMouse.h src/crossplatform/Linux/linuxMouse.cpp src/crossplatform/Linux/linuxMouse.h src/Managers/GUIManger.cpp src/Managers/GUIManger.h)
endif ()

# Managers source
set(src/Managers src/Managers/IOManager.h src/Managers/IOManager.cpp src/Managers/GUIManger.h src/Managers/GUIManger.cpp)

# Data source
set(src/Data src/Data/Mouse.h src/Data/data.h src/Data/data.cpp)

add_executable(KouseCPP src/main.cpp ${IMGUI_SRC} ${Mangers} ${Data} ${IO})


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
elseif (UNIX)
    target_link_libraries(KouseCPP dl)
    #include X11
    find_package(X11 REQUIRED)
    target_include_directories(KouseCPP PUBLIC ${X11_INCLUDE_DIR})
    target_link_libraries(KouseCPP ${X11_LIBRARIES})
elseif (APPLE)
    target_link_libraries(KouseCPP "-framework OpenGL")
endif()