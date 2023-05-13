#include "command.h"

char** strsplit(const char* data, const char* delim, int* argc) {
    size_t len = strlen(data);
    char* str = malloc(sizeof(len));
    char* tmp = data;
    int elements;
    strcpy(str, data);
    while(*tmp) {
        if(delim == *tmp) {
            elements++; 
        }
        tmp++;
    }
    
    int count=0;
    char** args = malloc(sizeof(char*) * elements);
    char* token = strtok(str, delim);
    if(args) {
        while(token) {
            args[count] = malloc(sizeof(255));
            strcpy(args[count], token);
            token = strtok(NULL, delim);
            count++;
        }
        *argc = count;
        return args;
    }
    
}

void command_execute(const int argc, char** argv) {
    if(!strcmp(argv[0], "say")) {
        if(argc < 2) {
            puts("Use say [args]");
        }
        char* str = argv[1];
        int count = 2;
        while(count < argc) {
            strcat(str, " ");
            strcat(str, argv[count]);
            count++;
        }
        printf("Captain says: %s\n", str);
    }
}