#include <iostream>
#include "SocketServer.h"

int main() {

    SocketServer socketServer(5000);

    socketServer.bindSocket();
    socketServer.listenSocket();
    socketServer.acceptSocket();


    return 0;
}