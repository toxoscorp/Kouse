//
// Created by trist on 2023-06-04.
//

#include "network.h"

#include "Data/data.h"
#include "Networking/Server.h"
#include "Networking/Client.h"

Network::Network() {
}

Network::~Network() {
}

void Network::send() {

}

void Network::init() {
    if (data::server){
        server.init();
    } else {
        client.init();
    }
}

void Network::stop() {
    if (data::server){
        server.stop();
    } else {
        client.stop();
    }
}

void Network::start() {
    if (data::server){
        server.start();
    } else {
        client.start();
    }
}

std::string Network::getIp() {
    return server.getIP();
}

