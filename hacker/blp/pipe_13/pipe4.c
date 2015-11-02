/*
 * =====================================================================================
 *
 *       Filename:  pipe4.c
 *
 *    Description:  consumer
 *
 *        Created:  10/10/2015 11:24:05 AM
 *       Compiler:  gcc
 *
 *         Author:  Alan Lee , 1127259111@qq.com
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{   
    int data_processed;
    char buffer[BUFSIZ + 1];
    int file_descriptor;

    memset(buffer, '\0', sizeof(buffer));
    sscanf(argv[1], "%d", &file_descriptor);
    data_processed = read(file_descriptor, buffer, BUFSIZ);

    printf("%d - read %d bytes : %s\n", getpid(), data_processed, buffer);

    return EXIT_SUCCESS;
}



