#include "main.h"
#include <unistd.h>

/**
 * exec - execute
 * @argv: vector
 * Return: void
 */

void exec(char **argv)
{
	char *command = NULL;

	if (argv)
	{
		command = argv[0];

		if (execve(command, argv, NULL) == -1)
		{
			perror("Error:");
		};
	}
}
