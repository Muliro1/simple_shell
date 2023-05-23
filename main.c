#include "main.h"

int main(int ac, char **argv)
{
    char *prompt = "$ ";
    char *command = NULL, *command_copy = NULL;
    size_t n = 0;
    ssize_t nchars_read;
    const char *delim = " \n";
    int token_count = 0;
    char *token;
    int i;

    /* declaring void variables */
    (void)ac;

    /* Create a loop for the shell's prompt */
    while (1)
    {
        printf("%s", prompt);
        nchars_read = getline(&command, &n, stdin);
        /* check if the getline function failed or reached EOF or user use CTRL + D */
        if (nchars_read == -1)
        {
            printf("Exiting shell....\n");
            return (-1);
        }

        /* allocate space for a copy of the lineptr */
        command_copy = malloc(sizeof(char) * nchars_read);
        if (command_copy == NULL)
        {
            perror("tsh: memory allocation error");
            return (-1);
        }
        /* copy lineptr to lineptr_copy */
        copy_str(command_copy, command);

        /********** split the string (lineptr) into an array of words ********/
        /* calculate the total number of tokens */
        token = strtok(command, delim);

        while (token != NULL)
        {
            token_count++;
            token = strtok(NULL, delim);
        }
        token_count++;

        /* Allocate space to hold the array of strings */
        argv = malloc(sizeof(char *) * token_count);

        /* Store each token in the argv array */
        token = strtok(command_copy, delim);

        for (i = 0; token != NULL; i++)
        {
            argv[i] = malloc(sizeof(char) *my_strlen(token));
            copy_str(argv[i], token);

            token = strtok(NULL, delim);
        }
        argv[i] = NULL;

        /* execute the command */
        exec(argv);
    }

    /* free up allocated memory */
    free(command_copy);
    free(command);

    return (0);
}
