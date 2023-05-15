#include"shell.h"

/**
 * prompt - This what will displayed on terminal
 * @av: argument variable
 * @env: enviroment variable
 * Return: 0 on success and -1 on otherwise
 */

int prompt(char **av, char **env)
{
	char *lineptr = NULL;
	size_t n = 0;
	char *argv[] = (NULL, NULL);
	ssize_t num_char;
	int i;
	int status;
	pid_t child_pid;

	while (1)
	{
		printf("shell-$ ");
		num_char = getline(&lineptr, &n, stdin);
		if(num_char == -1)
		{
			free(lineptr);
			exit(EXIT_FAILURE);
		}
		i = 0;
		while(lineptr[i])
		{
			if(lineptr[i] == '\n')
				lineptr[i] = 0;
		}
		argv[0] = lineptr;
		child_pid = fork();
		if(child_pid == -1)
		{
			free(lineptr);
			exit(EXIT_FAILURE);
		}
		if(child_pid == 0)
		{
			if (execve(argv[0], argv, env) == -1)
				printf("%s No such file or directory\n", av[0]);

		}
		else
		{
			wait(&status);
		}

	}
	return (0);
}
