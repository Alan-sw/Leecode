/*
 * =====================================================================================
 *
 *       Filename:  pipe5.c
 *
 *    Description:  use pipe to instead of stand input
 *
 *        Created:  10/12/2015 11:43:37 AM
 *       Compiler:  gcc
 *
 *         Author:  Alan Lee , 1127259111@qq.com
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    int data_processed;
    int file_pipes[2];
    const char some_data[] = "123";
    pid_t fork_result;

    if (pipe(file_pipes) == 0) {
        fork_result = fork();
        if (fork_result == (pid_t)-1) {
            fprintf(stderr, "Fork failure\n");
            return EXIT_FAILURE;
        }

        if (fork_result == (pid_t)0) {
            close(0);
            dup(file_pipes[0]);
            close(file_pipes[0]);
            close(file_pipes[1]);

            execlp("od", "od", "-c", (char*)0);
            return EXIT_FAILURE;
        } else {
            close(file_pipes[0]);
            data_processed = write(file_pipes[1], some_data, strlen(some_data));
            close(file_pipes[1]);
            printf("%d - wrote %d bytes\n", (int)getpid(), data_processed);
        }
    }

    return EXIT_SUCCESS;
}

