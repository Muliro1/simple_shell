#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void exec(char **argv);
char *copy_str(char *destination, char *source);
unsigned int my_strlen(const char *s);
#endif
