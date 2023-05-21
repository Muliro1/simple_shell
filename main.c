#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int ac, char **argv)
{
char *prompt = "($) ";
char *command = NULL;
char *command_copy = NULL;
const char *delim = " ";
int token_count = 0;
char *token;
int i;
size_t n = 0;
ssize_t nchars_read;

/* declaring void variables */
(void)ac;

/* create an infinite loop */
while (1)
{
	printf("%s", prompt);
	nchars_read = getline(&command, &n, stdin);
	/* check if the getline function failed or reached EOF or user use CTRL + D */
	if (nchars_read == -1)
	{
		return (-1);
	}
	command_copy = malloc(sizeof(char) * nchars_read);
	if (command_copy == NULL)
	{
		perror("memory allocation error");
		return (-1);
	}
	copy_str(command, command_copy);
	token = strtok(command, delim);
	while (token != NULL)
	{
		token_count++;
		token = strtok(NULL, delim);
	}
	token_count++;
	argv = malloc(sizeof(char *) * token_count);
	token = strtok(command_copy, delim);
	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(token));
	/**	copy_str(argv[i], token);**/
		strcpy(argv[i], token);
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	exec(argv);
}
free(command_copy);
free(command);

return (0);
}
