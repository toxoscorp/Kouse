//
// Created by trist on 2023-07-20.
//

#include "SIOSIOManager.h"

SIOS::IOManager::IOManager() {
}

SIOS::IOManager::~IOManager() {
}

void SIOS::IOManager::update() {
    for (const auto &item: devices) {
        item->update();
    }
}

void SIOS::IOManager::addDevice(SIOS::Devices::Device *device) {
    devices.push_back(device);
}

SIOS::Devices::Device *SIOS::IOManager::getDevice(SIOS::Devices::Type type) {
    for (const auto &item: devices) {
        if (item->getType() == type) {
            return item;
        }
    }
    return nullptr;
}
