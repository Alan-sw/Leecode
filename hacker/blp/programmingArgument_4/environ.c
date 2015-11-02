/*
 * =====================================================================================
 *
 *       Filename:  environ.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/19/2015 11:07:28 AM
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
#include <string.h>

int main(int argc, char *argv[])
{
    char *var, *value;

    if (argc == 1 || argc > 2) {
        fprintf(stderr, "usage:environ var [value] \n");
        return EXIT_FAILURE;
    }
    
    var = argv[1];
    value = getenv(var);
    
    if (value) {
        printf("Variable %s has value %s\n", var, value);
    }
    else {
        printf("Variable %s has no value \n", var);
    }











    return 0;
}
