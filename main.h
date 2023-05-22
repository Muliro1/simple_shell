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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void exec(char **argv);
char *copy_str(char *destination, char *source);
unsigned int my_strlen(const char *s);
#endif
