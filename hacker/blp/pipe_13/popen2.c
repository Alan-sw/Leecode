/*
 * =====================================================================================
 *
 *       Filename:  popen2.c
 *
 *    Description:  send something to external program
 *
 *        Created:  10/10/2015 09:37:30 AM
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
    FILE *write_fp;
    char buffer[BUFSIZ + 1];
    sprintf(buffer, "Once upon a time, there was...\n");
    write_fp = popen("od -c", "w");
    if (write_fp != NULL) {
        fwrite(buffer, sizeof(char), strlen(buffer), write_fp);
        pclose(write_fp);
        return EXIT_SUCCESS;
    }
    
    return EXIT_FAILURE;
}
