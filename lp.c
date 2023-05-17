#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define PROMPT "$ "

int prompt(char **env) {
    char lineptr[MAX_INPUT_SIZE];
    int child_status = 0;

    while (1) {
        // display prompt and get input from user
        printf("%s", PROMPT);
        fgets(lineptr, MAX_INPUT_SIZE, stdin);

        // remove newline character from end of input
        size_t len = strlen(lineptr);
        if (len > 0 && lineptr[len - 1] == '\n') {
            lineptr[len - 1] = '\0';
        }

        // tokenize input
        char *token = strtok(lineptr, " ");
        char *argv[3] = {NULL, NULL, NULL};
        int argc = 0;
        while (token != NULL && argc < 2) {
            argv[argc++] = token;
            token = strtok(NULL, " ");
        }

        // exit if no command was entered
        if (argc == 0) {
            continue;
        }

        // fork and execute command
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
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

    return 0;
}

int main(int argc, char **argv, char **envp) {
    prompt(envp);
    return 0;
}
