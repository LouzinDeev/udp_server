#include "main.h"

int main(int argc, char** argv) {
    client_t client;
    client_setup(&client, "127.0.0.1", 3132);
    client_send(client, argv[1]);
    return 0;
}