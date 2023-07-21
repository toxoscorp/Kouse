//
// Created by trist on 2023-07-20.
//

#ifndef KOUSECPP_SIOSMOUSE_H
#define KOUSECPP_SIOSMOUSE_H

#include "SIOSDevices.h"

namespace SIOS {
    namespace Devices {
        class Mouse : Device {
        public:
            Mouse() : Device(MOUSE) {};
            ~Mouse();

            void update() override;

        private:

        };
    }
}

#endif //KOUSECPP_SIOSMOUSE_H
