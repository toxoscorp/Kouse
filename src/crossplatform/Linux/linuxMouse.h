//
// Created by cyber-toxo on 7/12/23.
//

#ifndef KOUSECPP_LINUXMOUSE_H
#define KOUSECPP_LINUXMOUSE_H

#include <X11/Xlib.h>

#include <iostream>

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

#endif //KOUSECPP_LINUXMOUSE_H
