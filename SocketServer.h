//
// Created by valentin on 9/27/16.
//

#ifndef CPP_SOCKET_SOCKETSERVER_H
#define CPP_SOCKET_SOCKETSERVER_H


#include "Socket.h"

class SocketServer : public Socket {


public:
    SocketServer(uint16_t port);

    void bindSocket();

    void listenSocket();

    void acceptSocket();


};


#endif //CPP_SOCKET_SOCKETSERVER_H
