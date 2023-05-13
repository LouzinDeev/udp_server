#include "client.h"

void client_setup(client_t* client, const char* ip, const uint16_t port) {

    memset(&client->addr, 0, sizeof(client->addr));
    client->addr.sin_addr.s_addr = inet_addr(ip);
    client->addr.sin_family = AF_INET;
    client->addr.sin_port = htons(port);
    client->addrLen = sizeof(client->addr);

    client->ip = malloc(sizeof(255));
    strncpy(client->ip, ip, sizeof(255));
    client->port = port;

    client->socket = socket(AF_INET, SOCK_DGRAM, 0);
}

void client_send(client_t client, const char* buffer) {
    int res = sendto(client.socket, buffer, 255, 0, (const struct sockaddr*)&client.addr, client.addrLen);
    if(res < 0) {
        perror("sento error");
    } else {
        puts("Sended.");
    }
}