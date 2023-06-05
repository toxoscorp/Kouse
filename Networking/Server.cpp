//
// Created by trist on 2023-06-04.
//

#include "Server.h"

#include <iostream>

Server::Server() {
    if (enet_initialize() != 0) {
        std::cout << "An error occurred while initializing ENet." << std::endl;
        exit(EXIT_FAILURE);
    }
    atexit(enet_deinitialize);
}

Server::~Server() {
    enet_host_destroy(server);
}

void Server::start() {
    address.host = ENET_HOST_ANY;
    address.port = 1234;

    server = enet_host_create(&address, 32, 2, 0, 0);
    if (server == nullptr) {
        std::cout << "An error occurred while trying to create an ENet server host." << std::endl;
        exit(EXIT_FAILURE);
    }
}

void Server::stop() {

}

void Server::send() {

}

void Server::receive() {

}
