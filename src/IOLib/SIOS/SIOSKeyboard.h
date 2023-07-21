//
// Created by trist on 2023-07-20.
//

#ifndef KOUSECPP_SIOSKEYBOARD_H
#define KOUSECPP_SIOSKEYBOARD_H

#include "SIOSDevices.h"

namespace SIOS {
    namespace Devices {
        class Keyboard : Device {
        public:
            Keyboard() : Device(KEYBOARD) {};
            ~Keyboard();

            void update() override;
        };
    }
}

#endif //KOUSECPP_SIOSKEYBOARD_H
