//
// Created by trist on 2023-06-04.
//

#include "winMouse.h"

#include <iostream>
#include <windows.h>

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
            case WM_MOUSEMOVE: {
                MSLLHOOKSTRUCT *pMouseStruct = (MSLLHOOKSTRUCT *) lParam;
                x = pMouseStruct->pt.x;
                y = pMouseStruct->pt.y;
                std::cout << "x: " << x << " y: " << y << std::endl;
                dx = x - px;
                dy = y - py;
                px = x;
                py = y;
                std::cout << "dx: " << dx << " dy: " << dy << std::endl;
                //CURSORINFO info;
                //GetCursorInfo(&info);
                //std::cout << info.flags << std::endl;
                //https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-showcursor
                //https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getcursorinfo
                // https://learn.microsoft.com/en-us/windows/win32/api/winuser/ns-winuser-cursorinfo
                if (!enabled) return 1;
                break;
            }
            case WM_MOUSEWHEEL: {
                MSLLHOOKSTRUCT *pMouseStruct = (MSLLHOOKSTRUCT *) lParam;
                int wheel = pMouseStruct->mouseData;
                std::cout << "wheel: " << wheel << std::endl;
                break;
            }
            default:
                break;
        }
    }
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

void sys::initializeMouseSys() {

    HHOOK mouseHook = SetWindowsHookEx(WH_MOUSE_LL, mouseProc, NULL, 0);
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