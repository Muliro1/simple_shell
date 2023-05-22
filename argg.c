#include "main.h"


int prompt(char **env)
{
	
  char *lineptr = NULL;
  size_t n = 0;
  ssize_t numbers_read;
  int child_status = 0;

  while (1)
  {
    /* display prompt and get input from user */
    printf("%s", PROMPT);
    numbers_read = getline(&lineptr, &n, stdin);
    if (numbers_read == -1)
    {
      if (feof(stdin))
      {
        printf("\n");
        free(lineptr);
        exit(EXIT_SUCCESS);
      } else
      {
        perror("getline");
        exit(EXIT_FAILURE);
      }
    }

    /*remove newline character from end of input */
    if (lineptr[numbers_read - 1] == '\n') {
      lineptr[numbers_read - 1] = '\0';
    }

    // tokenize input
    char *token = strtok(lineptr, " ");
    char *argv[2] = {NULL, NULL};
    int argc = 0;
    while (token != NULL && argc < 2) {
      argv[argc++] = token;
      token = strtok(NULL, " ");
    }

    /* exit if no command was entered */
    if (argc == 0)
    {
      continue;
    }

    // fork and execute command
    pid_t pid = fork();
    if (pid < 0)
    {
      perror("fork");
      exit(EXIT_FAILURE);
    } else if (pid == 0)
    {
      // child process
      if (execve(argv[0], argv, env) == -1) {
        perror(argv[0]);
        exit(EXIT_FAILURE);
      }
    } else {
      // parent process
      if (wait(&child_status) == -1) {
        perror("wait");
        exit(EXIT_FAILURE);
      }
    }
  }

  free(lineptr);
  return 0;
}

int main(int argc, char **argv, char **envp) {
  prompt(envp);
  return 0;
}
