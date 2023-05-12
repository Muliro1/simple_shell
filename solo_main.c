#include "main.h"

int main(int ac, char **argv)
{

	while(1)
	{
	char *prompt ="myshell-> ";
	char *lineptr;
	size_t n = 0;

// declaring void var
	(void)ac; (void)argv;


	printf("%s", prompt);
	
	getline(&lineptr, &n, stdin);
	
	printf("%s\n", lineptr);
	
	free(lineptr);
	}

	return (0);
}
