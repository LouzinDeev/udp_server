#include "server.h"

void server_setup(server_t* server, uint16_t port, uint16_t max_connections) {
    server->port = port;
    server->max_connections = max_connections;

    struct sockaddr_in ad;
    ad.sin_addr.s_addr = INADDR_ANY;
    ad.sin_family = AF_INET;
    ad.sin_port = htons(port);
    server->addr = ad;
    
    server->addrLen = sizeof(server->addr);

    server->listener = socket(AF_INET, SOCK_DGRAM, 0);

    if(bind(server->listener, (const struct sockaddr*)&server->addr, sizeof(server->addr)) < 0) {
        perror("Bind error");
        exit(1);
    }
}

void* callback_handler(void* param) {
    server_t* server = (server_t*)param;
    while(1) {
        char buffer[255];
        int res = recvfrom(server->listener, buffer, sizeof(buffer), 0, NULL, NULL);
        if(res < 0) {
            perror("Recv error.");
            pthread_exit(NULL);
        } else if(res == 0) {
            continue;
        } else {
            buffer[res] = '\0';
            server->callback(buffer);
        }
    }
}

void server_tlisten(server_t* server, callback_listen_t callback) {
    pthread_t thread;
    server->callback = callback;
    pthread_create(&thread, NULL, callback_handler, (void*)server);
}