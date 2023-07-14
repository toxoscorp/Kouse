//
// Created by trist on 2023-06-04.
//

#ifndef KOUSECPP_DATA_H
#define KOUSECPP_DATA_H

#include "Mouse.h"

#include <string>

namespace data {
    extern Mouse mouse;
    extern int ip[4];
    extern bool onPc;
    extern bool connected;
    extern bool server;
    extern std::string serverIp;
    extern int port;
}

#endif //KOUSECPP_DATA_H
