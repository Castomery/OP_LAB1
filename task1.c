#include "sys/wait.h"
#include "stdio.h"
#include "unistd.h"

int main()
{
    int pid = fork();

    if (pid == 0)
    {
    }
    else
    {
        if (fork() == 0)
        {
        }
        else
        {
            if (fork() == 0)
            {
            }
            else
            {
                if (fork() == 0)
                {
                    fork();
                }
                else
                {
                    if (fork() == 0)
                    {
                    }
                    else
                    {
                    }
                }
            }
        }
    }

    sleep(10000);
    return 0;
}