#include "main.h"

void callback_listen(const char* data) {
    int argc = 0;
    char** argv = strsplit(data, " ", &argc);
    command_execute(argc, argv);
}


int main(int argc, char** argv) {
    server_t server;
    server_setup(&server, 3132, 5);
    server_tlisten(&server, callback_listen);
    sleep(atoi(argv[1]));
    return 0;
}