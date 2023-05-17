#include "shell.h"

int main(int argc, char **argv, char **envp)
{
	prompt(argv, envp);
	return 0;
}

int prompt(char **av, char **env)
{
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t num_char;
	int status;

	while (1)
	{
		printf("shell-$ ");
		num_char = getline(&lineptr, &n, stdin);
		if(num_char == -1)
		{
			free(lineptr);
			exit(EXIT_FAILURE);
		}
		// remove newline character from the end of the input
		if(lineptr[num_char - 1] == '\n')
			lineptr[num_char - 1] = '\0';

		// split the input into tokens
		char *token = strtok(lineptr, " ");
		char *argv[10];
		int argc = 0;
		while (token != NULL && argc < 10)
		{
			argv[argc++] = token;
			token = strtok(NULL, " ");
		}
		argv[argc] = NULL; // set the last element of argv to NULL

		pid_t child_pid = fork();
		if(child_pid == -1)
		{
			free(lineptr);
			exit(EXIT_FAILURE);
		}
		if(child_pid == 0)
		{
			if (execve(argv[0], argv, env) == -1)
				printf("%s No such file or directory\n", argv[0]);
			exit(EXIT_FAILURE); // exit child process if execve() fails

		}
		else
		{
			wait(&status);
		}
	}
	free(lineptr);
	return (0);
}

