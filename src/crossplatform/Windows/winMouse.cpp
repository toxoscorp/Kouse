//
// Created by trist on 2023-06-04.
//

#include "winMouse.h"

#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

bool enabled = true;

int px = 0;
int py = 0;
int dx = 0;
int dy = 0;
int x = 0;
int y = 0;

LRESULT CALLBACK mouseProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode >= 0) {
        switch (wParam) {
            case WM_MOUSEWHEEL: {
                MSLLHOOKSTRUCT *pMouseStruct = (MSLLHOOKSTRUCT *) lParam;
                int wheel = pMouseStruct->mouseData;
                std::cout << "wheel: " << wheel << std::endl;
                break;
            }
            case WM_LBUTTONDOWN: {
                MSLLHOOKSTRUCT *pMouseStruct = (MSLLHOOKSTRUCT *) lParam;
                std::cout << "click" << std::endl;
                break;
            }
            case WM_LBUTTONUP: {
                MSLLHOOKSTRUCT *pMouseStruct = (MSLLHOOKSTRUCT *) lParam;
                std::cout << "release" << std::endl;
                break;
            }
            default:
                break;
        }
    }
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

void sys::initializeMouseSys() {
//    HHOOK mouseHook = SetWindowsHookEx(WH_MOUSE_LL, mouseProc, NULL, 0); --> crash the mouse and make it unusable for the rest of the session (need a reboot)
}

int sys::getMouseXSys() {
    return x;
}

int sys::getMouseYSys() {
    return y;
}

void sys::setMousePositionSys(int x, int y) {
    SetCursorPos(x, y);
}

void sys::disableMouseSys() {
    enabled = false;
}

void sys::enableMouseSys() {
    enabled = true;
}

int sys::getDeltaMouseYSys() {
    return dy;
}

int sys::getDeltaMouseXSys() {
    return dx;
}

std::pair<int,int> sys::getMousePositionSys() {
    POINT cursorPos;
    std::pair<int, int> pos;
    if (GetCursorPos(&cursorPos))
    {
        pos.first = cursorPos.x;
        pos.second = cursorPos.y;
        return pos;
    } else {
        pos.first = 0;
        pos.second = 0;
        return pos;
    }
}
