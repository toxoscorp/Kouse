//
// Created by cyber-toxo on 7/12/23.
//

#ifndef KOUSECPP_LINUXMOUSE_H
#define KOUSECPP_LINUXMOUSE_H

#include <X11/Xlib.h>

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

#endif //KOUSECPP_LINUXMOUSE_H
