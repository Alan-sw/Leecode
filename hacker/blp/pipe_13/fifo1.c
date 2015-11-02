/*
 * =====================================================================================
 *
 *       Filename:  fifo1.c
 *
 *    Description:  named piped
 *
 *        Created:  10/12/2015 02:18:40 PM
 *       Compiler:  gcc
 *
 *         Author:  Alan Lee , 1127259111@qq.com
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(void)
{
    int res = mkfifo("./myfifo", 0777);
    if (res == 0) {
        printf("FIFO created\n");
    }

    return EXIT_SUCCESS;
}
