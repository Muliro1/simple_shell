#include "shell.h"
int main(int ac, char**av, char **env)
{
    if (av == -1) 
    {
        prompt(av, env);
        return (0);
    }
    
}