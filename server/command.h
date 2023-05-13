#ifndef _COMMAND_H_
#define _COMMAND_H_
#include "main.h"

char** strsplit(const char* data, const char* delim, int* argc);
void command_execute(const int argc, char** argv);

#endif