//
// Created by trist on 2023-06-04.
//

#include "Client.h"

#include <iostream>

Client::Client() {
    if (enet_initialize() != 0) {
        std::cout << "An error occurred while initializing ENet." << std::endl;
        exit(EXIT_FAILURE);
    }
    atexit(enet_deinitialize);
}

Client::~Client() {
    enet_host_destroy(client);
}

void Client::start() {
    client = enet_host_create (NULL /* create a client host */,
                               1 /* only allow 1 outgoing connection */,
                               2 /* allow up 2 channels to be used, 0 and 1 */,
                               0 /* assume any amount of incoming bandwidth */,
                               0 /* assume any amount of outgoing bandwidth */);
    if (client == NULL)
    {
        fprintf (stderr,
                 "An error occurred while trying to create an ENet client host.\n");
        exit (EXIT_FAILURE);
    }
}

void Client::stop() {

}

void Client::send() {

}

void Client::receive() {

}
