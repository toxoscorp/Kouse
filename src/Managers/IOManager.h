//
// Created by trist on 2023-06-04.
//

#ifndef KOUSECPP_IOMANAGER_H
#define KOUSECPP_IOMANAGER_H

class IOManager {
public:
    IOManager();
    ~IOManager();
    void update();
    void setMousePosition(int x, int y);
    int getMouseX();
    int getMouseY();
    int getMouseWheel();

private:
    int mouseX;
    int mouseY;
    int mouseWheel;
};

#endif //KOUSECPP_IOMANAGER_H
