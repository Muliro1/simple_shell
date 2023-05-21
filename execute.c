#include "main.h"
#include <unistd.h>

/**
 * exec - function
 * @argv: the argjument
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
