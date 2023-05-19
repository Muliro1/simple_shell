#include "main.h"

int main(int ac, char **argv){
  char *prompt = "($) ";
  char *lineptr;
  char *lineptr_copy = NULL;
  const char *delim = " \n";

  size_t n = 0; 
  ssize_t nchars_read;

   /* declaring void variables */
  (void)ac; (void)argv;

    /* create an infinite loop */
    while (1){
      printf("%s", prompt);
      nchars_read = getline(&lineptr, &n, stdin);
      /* check if the getline function failed or reached EOF or user use CTRL + D */ 
        if (nchars_read == -1){
            return (-1);
        }

      printf("%s\n", lineptr);

         
    }
  free(lineptr); 

  return (0);
}
