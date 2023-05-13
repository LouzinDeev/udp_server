#ifndef _CLIENT_H_
#define _CLIENT_H_
#include "main.h"

typedef struct {
    char* ip;
    uint16_t port;
    struct sockaddr_in addr;
    socklen_t addrLen;
    int socket;
}client_t;

void client_setup(client_t* client, const char* ip, const uint16_t port);
void client_send(client_t client, const char* buffer);

#endif