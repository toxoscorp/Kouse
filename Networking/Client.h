//
// Created by trist on 2023-06-04.
//

#ifndef KOUSECPP_CLIENT_H
#define KOUSECPP_CLIENT_H

#include <enet/enet.h>

class Client {
private:
    ENetHost* client;

public:
    Client();
    ~Client();
    void start();
    void stop();
    void send();
    void receive();
};


#endif //KOUSECPP_CLIENT_H
