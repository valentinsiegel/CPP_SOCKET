#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <string>

#ifndef CPP_SOCKET_SOCKET_H
#define CPP_SOCKET_SOCKET_H

using namespace std;

class Socket {

public:

    struct sockaddr_in sockaddrIn;
    string ipName;
    int socketDescriptor;

    Socket(string name, uint16_t port);

    Socket(uint16_t port);

    hostent *getIpByName(string name);

    void createSocket();

    void connectSocket();

    void sendSocket(string message);

    void receive();

};

#endif //CPP_SOCKET_SOCKET_H
