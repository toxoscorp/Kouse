//
// Created by trist on 2023-06-04.
//

#ifndef KOUSECPP_NETWORK_H
#define KOUSECPP_NETWORK_H

#include <string>
#include "Networking/Client.h"
#include "Networking/Server.h"

class Network {
public:
    Network();
    ~Network();
    void send();
    void init();
    void stop();
    void start();
    std::string getIp();

private:
    Client client;
    Server server;
};


#endif //KOUSECPP_NETWORK_H
