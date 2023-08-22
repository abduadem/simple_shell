#include "shell.h" /*this shell.c is where the main functions will be*/
int main(int ac, char **av, char **env)
{
    if (ac == 1) /*argument count = 1 (since, the task suggests we to do as this)*/
    {
        prompt(av, env); /*prompt = (JUST RANDOM NAME GIVEN) ; this prompt will take the two arguments; need to create for this (prompt.c is the function I created for this purpose)*/
    }  /*after excuting the prompt function(going to the prompt.c and run all of it.) , it will take  the vector argument and the enviroment variable*/
    return (0);
}
