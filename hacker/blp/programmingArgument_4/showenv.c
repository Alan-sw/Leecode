/*
 * =====================================================================================
 *
 *       Filename:  showenv.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/19/2015 11:30:37 AM
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

extern char **environ;

int main(int argc, char *argv[])
{
    char **env = environ;
    while (*env) {
        printf("%s\n", *env);
        env++;
    }
    return 0;
}
