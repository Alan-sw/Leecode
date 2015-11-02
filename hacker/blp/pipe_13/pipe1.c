/*
 * =====================================================================================
 *
 *       Filename:  pipe1.c
 *
 *    Description:  use pipe instead of popen
 *
 *        Created:  10/10/2015 10:35:38 AM
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
    char buffer[BUFSIZ + 1];
    
    memset(buffer, '\0', sizeof(buffer));
    if (pipe(file_pipes) == 0) {
        data_processed = write(file_pipes[1], some_data, strlen(some_data));
        printf("Wrote %d bytes\n", data_processed);
        data_processed = read(file_pipes[0], buffer, BUFSIZ);
        printf("Read %d bytes: %s\n\n", data_processed, buffer);
        printf("the file_pipes[0] is : %d\n", file_pipes[0]);
        printf("the file_pipes[1] is : %d\n", file_pipes[1]);
        return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
}
