//
// Created by trist on 2023-06-04.
//

#ifndef KOUSECPP_SERVER_H
#define KOUSECPP_SERVER_H

#include <enet/enet.h>

class Server {
private:
    ENetHost* server;
    ENetAddress address;

public:
    Server();
    ~Server();
    void start();
    void stop();
    void send();
    void receive();
};


#endif //KOUSECPP_SERVER_H
