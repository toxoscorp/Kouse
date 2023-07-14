//
// Created by trist on 2023-06-04.
//

#ifndef KOUSECPP_WINMOUSE_H
#define KOUSECPP_MOUSE_H


class Mouse {
public:
    int x;
    int y;
    int lastX;
    int lastY;
    int wheel;
    int lastWheel;
    int deltaX;
    int deltaY;
    int deltaWheel;
    bool leftButton;
    bool rightButton;
    bool middleButton;

    Mouse(){
        x = 0;
        y = 0;
        lastX = 0;
        lastY = 0;
        wheel = 0;
        lastWheel = 0;
        deltaX = 0;
        deltaY = 0;
        deltaWheel = 0;
        leftButton = false;
        rightButton = false;
        middleButton = false;
    };
};


#endif //KOUSECPP_WINMOUSE_H
