//
// Created by trist on 2023-06-04.
//

#ifndef KOUSECPP_WINMOUSE_H
#define KOUSECPP_WINMOUSE_H

#include <windows.h>
namespace sys {
    void initializeMouseSys();
    int getMouseXSys();
    int getMouseYSys();

    void setMousePositionSys(int x, int y);

    void disableMouseSys();
    void enableMouseSys();

    int getDeltaMouseYSys();
    int getDeltaMouseXSys();
}

#endif //KOUSECPP_WINMOUSE_H
