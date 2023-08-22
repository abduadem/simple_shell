#include "shell.h" /*For Task-1&2*/

#define MAX_CMD 10 /*added (MAX_COMMAND just RANDOM NAME GIVEN)*/

void prompt(char **av, char **env) 
{
    char *strg = NULL;
    int b, z, stat; /*j is declared for checking the return value of strtok() function.*/
    size_t y = 0;
    ssize_t no_char; 
    char *argv[MAX_CMD]; /*changed*/
    pid_t child_pid;

    while(1)
    {
        if(isatty(STDIN_FILENO)) /*tests whether a file descriptor refers to a terminal and removes the "cisfun$ cisfun$" from the terminal while in the non interactive mode using echo "/bin/ls" | ./hsh */
        printf("cisfun$ "); /*this command the user type in is *str argument from man page(char *strtok(char *str, const char *delim);)*/

        no_char = getline(&strg, &y, stdin); /**/
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
                /*it will not buckle up all at once in each and every command I needed to do, in every new command my j value will be also 0 and do the fetching, do the breaking of the tokens all again for all FRESH.(If it was out of the loop declared above, none of this will not be happening)*/
        z = 0; /*initialized it here inside the while function above Bcoz the program will not start fresh if i needed to go with doing my second command and so on*/ 
        argv[z] = strtok(strg, " "); /*first argument= strg, and second argument = delimitter(which is a space) , I could use argv[0] and it has same meaning,no value change and the 1st token will be stored in here*/
        while(argv[z]) /*used for fetching the other argument and also can be writeen as while([argv != NULL])*/
        {
            ++z; /*let my incrementation be in here and here, after being incremented, the 2nd token will be stored*/
            argv[z] = strtok(NULL, " "); /*(I could increment it in here too by doing(argv[++j] to do 2 tasks within single line)strg set to NULL, telling the strtok() function that it should continue from where it has stopped.*/
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
