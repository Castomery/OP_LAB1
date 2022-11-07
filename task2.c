#include <locale.h>
#include "sys/wait.h"
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

int main(int argc, char *argv[])
{
    int pid = fork();
    int status = 0;

    if (pid == 0)
    {
        char *currArgv[argc];

        for (int i = 1; i < argc; i++)
        {
            currArgv[i - 1] = argv[i];
        }

        currArgv[argc - 1] = NULL;

        execvp(argv[1], currArgv);
    }
    else
    {
        waitpid(pid, &status, 0);
        if (status != 0)
        {
            printf("Failed, exit code = %d\n", status);
        }
        else
        {
            printf("Success!");
        }
    }

    return 0;
}