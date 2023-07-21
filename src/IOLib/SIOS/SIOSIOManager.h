//
// Created by trist on 2023-07-20.
//

#ifndef KOUSECPP_SIOSIOMANAGER_H
#define KOUSECPP_SIOSIOMANAGER_H

#include <vector>
#include "SIOSDevices.h"

namespace SIOS {

    class IOManager {
    public:
        IOManager();
        ~IOManager();

        void update();

        void addDevice(Devices::Device* device);

        Devices::Device* getDevice(Devices::Type type);

    private:
        std::vector<Devices::Device*> devices;


    };
}

#endif //KOUSECPP_SIOSIOMANAGER_H
