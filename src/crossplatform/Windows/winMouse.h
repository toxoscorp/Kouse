//
// Created by trist on 2023-06-04.
//

#ifndef KOUSECPP_WINMOUSE_H
#define KOUSECPP_WINMOUSE_H

#ifdef _WIN32
#include <windows.h>
#endif

#include <utility>

namespace sys {
    void initializeMouseSys();
    int getMouseXSys();
    int getMouseYSys();
    std::pair<int,int> getMousePositionSys();

    void setMousePositionSys(int x, int y);

    void disableMouseSys();
    void enableMouseSys();

    int getDeltaMouseYSys();
    int getDeltaMouseXSys();
}

#endif //KOUSECPP_WINMOUSE_H
