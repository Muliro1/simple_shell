#include "main.h"
#include <unistd.h>
#include <stdio.h>

/**
 * exec - function
 * @argv: the argjument
 * @argc: count.
 * @envp: env variables
 * Return: executed..
 */

int exec(int argc, char **argv, char *envp[])
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
	printf("done");
	return (0);
}
