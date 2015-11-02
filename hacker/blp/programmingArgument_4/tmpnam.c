/*
 * =====================================================================================
 *
 *       Filename:  tmpnam.c
 *
 *    Description:  tmpnam and tmpfile function
 *
 *        Version:  1.0
 *        Created:  08/19/2015 04:07:01 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Lee (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char tmpname[L_tmpnam];
    char *filename;
    FILE *tmpfp;

    filename = tmpnam(tmpname);
    
    printf("Temporary file name is : %s\n", filename);
    tmpfp = tmpfile();
    if (tmpfp) {
        printf("Opened a temporary file OK\n");
    } else {
        perror("tmpfile");
    }


    return 0;
}

