#include "shell.h"

int main(int ac, char **argv)
{
	/* Typing out what our prompt will look like*/
	char *prompt = "--$ ";
	/*char *lineptr to store the address of the buffer holding whatever was typed.*/
	char *lineptr;
	(void) ac; (void) argv;

	/*size_t n to store the allocated size in bytes.*/
	size_t n = 0;

	ssize_t numchar_read;
	char *lineptr_copy = NULL
	/* declaring delimiter */
	const char *delim = " \n";
	/** declaring an infinite loop for our prompt*/
	while(1)
	{
	printf("%s ", prompt);
	numchar_read = getline(&lineptr, &n, stdin);
	/* check if the getline function failed or reached EOF or user use CTRL + D */
	if (numchar_read == -1)
	{
		printf("Exiting the shell\n");
		return (-1);
	}

	printf("%s\n", lineptr);
	}
  	/* free up alocated memory */
	free(lineptr);
	return (0);
}
