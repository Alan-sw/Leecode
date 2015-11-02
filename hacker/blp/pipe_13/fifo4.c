/*
 * =====================================================================================
 *
 *       Filename:  fifo4.c
 *
 *    Description:  consumer
 *
 *        Created:  10/12/2015 03:48:15 PM
 *       Compiler:  gcc
 *
 *         Author:  Alan Lee , 1127259111@qq.com
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>

#define FIFO_NAME "./myfifo"
#define BUFFER_SIZE PIPE_BUF

int main(void)
{
    int pipe_fd;
    int res;
    int open_mode = O_RDONLY;
    char buffer[BUFFER_SIZE + 1];
    int bytes_read = 0;

    memset(buffer, '\0', sizeof(buffer));

    printf("Process %d opening FIFO O_RDONLY\n", getpid());
    pipe_fd = open(FIFO_NAME, open_mode);
    printf("Process %d result %d\n", getpid(), pipe_fd);

    if (pipe_fd != -1) {
        do {
            res = read(pipe_fd, buffer, BUFFER_SIZE);
            bytes_read += res;
        } while(res > 0);
        (void)close(pipe_fd);
    } else {
        return EXIT_FAILURE;
    }
    printf("Process %d finished, %d bytes read\n", getpid(), bytes_read);

    return EXIT_SUCCESS;
}
