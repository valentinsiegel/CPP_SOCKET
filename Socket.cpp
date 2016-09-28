//
// Created by valentin on 9/27/16.
//

#include "Socket.h"

Socket::Socket(string name, uint16_t port) {

    sockaddrIn.sin_family = AF_INET;
    sockaddrIn.sin_port = htons(port);

    hostent *_hostent = getIpByName(name);
    memcpy(&sockaddrIn.sin_addr, _hostent->h_addr_list[0], (size_t) _hostent->h_length);

    socketDescriptor = socket(AF_INET, SOCK_STREAM, 0);
}

Socket::Socket(uint16_t port) {

    sockaddrIn.sin_port = htons(port);

}

hostent *Socket::getIpByName(string name) {

    hostent *pHostent = gethostbyname(name.c_str());
    if (pHostent == NULL) {
        perror("Error resolving hostname.\n");
    }
    return pHostent;
}

void Socket::createSocket() {
}

void Socket::connectSocket() {
    if (connect(socketDescriptor, (const struct sockaddr *) &sockaddrIn, sizeof(sockaddrIn)) < 0) {
        perror("Error connecting the socket\n");
    }
}

void Socket::sendSocket(string message) {
    if (send(socketDescriptor, message.c_str(), strlen(message.c_str()), 0) < 0) {
        perror("Error sending data\n");
    }
}

void Socket::receive() {

    char buffer[1024];
    unsigned int nbChars;

    printf("Receiving response\n");

    do {
        nbChars = (unsigned int) recv(socketDescriptor, buffer, (size_t) buffer[1024], 0);

        for (int i = 0; i < nbChars; ++i) {
            printf("%c", buffer[nbChars]);
        }

    } while (nbChars > 0);

    printf("\nEnd of response\n");

    close(socketDescriptor);
}


