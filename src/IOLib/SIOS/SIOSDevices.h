//
// Created by trist on 2023-07-20.
//

#ifndef KOUSECPP_SIOSDEVICES_H
#define KOUSECPP_SIOSDEVICES_H

namespace SIOS {
    namespace Devices {
        enum Type {
            MOUSE,
            KEYBOARD
        };

        class Device {
        public:
            Device(Type type) : type(type) {};
            ~Device();

            virtual void update() = 0;

            Type getType() { return type; };

        private:
            Type type;
        };
    }
}

#endif //KOUSECPP_SIOSDEVICES_H
