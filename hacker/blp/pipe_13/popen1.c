/*
 * =====================================================================================
 *
 *       Filename:  popen1.c
 *
 *    Description:  use pipe and uname -a
 *
 *        Created:  10/10/2015 09:26:11 AM
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
    FILE *read_fp;
    char buffer[BUFSIZ + 1];
    int chars_read;
    memset(buffer, '\0', sizeof(buffer));
    read_fp = popen("uname -a", "r");
    if (read_fp != NULL) {
        chars_read = fread(buffer, sizeof(char), BUFSIZ, read_fp);
        if (chars_read > 0) {
            printf("Output was : \n%s\n", buffer);
        }
        pclose(read_fp);
        return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
}
