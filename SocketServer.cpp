#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include "SocketServer.h"


SocketServer::SocketServer(uint16_t port) : Socket(port) {

    sockaddrIn.sin_family = PF_INET;
    sockaddrIn.sin_addr.s_addr = INADDR_ANY;

    socketDescriptor = socket(PF_INET, SOCK_STREAM, 0);
}

void SocketServer::bindSocket() {
    if (bind(socketDescriptor, (const struct sockaddr *) &sockaddrIn, (socklen_t) (sizeof(sockaddrIn) < 0))) {
        perror("Error binding server socket\n");
    } else {
        printf("Bound Socket\n");
    }
}

void SocketServer::listenSocket() {
    if (listen(socketDescriptor, 1) < 0) {
        perror("Error while listening\n");
    } else {
        printf("Server listening");
    }
}

void ::SocketServer::acceptSocket() {
    int clientSocketDesc;
    struct sockaddr_in clientAddress;
    unsigned int clientAddressLenght;

    printf("server waiting");

    clientSocketDesc = accept(socketDescriptor, (sockaddr *) &clientAddress, &clientAddressLenght);
}