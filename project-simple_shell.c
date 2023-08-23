#include "shell.h"
#define MAX_CMD 10

void prompt(char **av, char **env) 
{
    char *strg = NULL;
    int b, z, stat; 
    size_t y = 0;
    ssize_t no_char; 
    char *argv[MAX_CMD]; 
    pid_t child_pid;
    while(1)
    {
        if(isatty(STDIN_FILENO)) 
        printf("cisfun$ "); 
        no_char = getline(&strg, &y, stdin); 
        if(no_char == -1)
        {
            free(strg); 
            exit(EXIT_FAILURE); 
        }
        while(strg[b]) 
        { 
            if(strg[b] == '\n')
                strg[b] = 0;
            b++;
        }
            
        z = 0;
        argv[z] = strtok(strg, " ");
        while(argv[z]) 
        {
            ++z; 
            argv[z] = strtok(NULL, " "); 
        }
        child_pid = fork(); 
        if(child_pid == -1) 
        {
            free(strg); 
            exit(EXIT_FAILURE);      
        }
        if(child_pid == 0) 
        {
            if(execve(argv[0], argv, env) == -1)
                printf("%s: No such file or directory\n", av[0]);
        }
        else
            wait(&stat);
    } 
}
