#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int exec(int argc, char **argv, char *envp[]);
char *copy_str(char *destination, char *source);
unsigned int my_strlen(const char *s);
char *get_path(char *command);
#endif
