#ifndef MAIN_H
#define MAIN_H
#define PROMPT "--$ "
#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void exec(char **argv);
char *copy_str(char *destination, char *source);
int copy_str(char str[100],char copy_str[100]);
unsigned int my_strlen(const char *s);
#endif

