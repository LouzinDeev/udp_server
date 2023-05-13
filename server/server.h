#ifndef _SERVER_H_
#define _SERVER_H_
#include "main.h"

typedef void (*callback_listen_t)(const char* data);

typedef struct {
    uint16_t port;
    uint16_t max_connections;
    int listener;
    struct sockaddr_in addr;
    socklen_t addrLen;

    callback_listen_t callback;
}server_t;

void server_setup(server_t* server, uint16_t port, uint16_t max_connections);
void server_tlisten(server_t* server, callback_listen_t callback);

#endif