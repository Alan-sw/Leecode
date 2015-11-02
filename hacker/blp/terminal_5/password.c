/*
 * =====================================================================================
 *
 *       Filename:  password.c
 *
 *    Description:  shutdown echo
 *
 *        Version:  1.0
 *        Created:  08/24/2015 11:06:10 AM
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
#include <termios.h>

#define PASSWORD_LEN 20

int main()
{
    struct termios initialresettings, newrsettings;
    char password[PASSWORD_LEN + 1];
    tcgetattr(fileno(stdin), &initialresettings);
    newrsettings = initialresettings;
    newrsettings.c_lflag &= ~ECHO;
    printf("Enter password:");

    if (tcsetattr(fileno(stdin), TCSAFLUSH, &newrsettings) != 0) {
        fprintf(stderr, "could not set attributes\n");
    } else {
        fgets(password, PASSWORD_LEN, stdin);
        tcsetattr(fileno(stdin), TCSANOW, &initialresettings);
        fprintf(stdout, "\nyou enter %s\n", password);
    }

    return 0;
}
