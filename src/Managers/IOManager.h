//
// Created by trist on 2023-06-04.
//

#ifndef KOUSECPP_IOMANAGER_H
#define KOUSECPP_IOMANAGER_H

class IOManager {
public:
    IOManager();
    ~IOManager();
    static void init();
    static void update();
    void setMousePosition(int x, int y);
    void disableKeyboard();
    void enableKeyboard();
    static int getMouseX();
    static int getMouseY();
};

#endif //KOUSECPP_IOMANAGER_H
