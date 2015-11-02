/*
 * =====================================================================================
 *
 *       Filename:  msg2.c
 *
 *    Description:  send message
 *
 *        Created:  10/15/2015 09:36:47 AM
 *       Compiler:  gcc
 *
 *         Author:  Alan Lee , 1127259111@qq.com
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#include <sys/msg.h>

#define MAX_TEXT 512

struct my_msg_st {
    long int my_msg_type;
    char some_text[BUFSIZ];
};


int main(void)
{
    int running = 1;
    struct my_msg_st some_data;
    int msgid;
    char buffer[BUFSIZ];

    msgid = msgget((key_t)1234, 0666| IPC_CREAT);
    if (msgid == -1) {
        fprintf(stderr, "msgget failed with error : %d\n", errno);
        return EXIT_FAILURE;
    }
    while (running) {
        printf("Enter some text: ");
        fgets(buffer, BUFSIZ, stdin);
        some_data.my_msg_type = 1;
        strcpy(some_data.some_text, buffer);

        if (msgsnd(msgid, (void*)&some_data, MAX_TEXT, 0) == -1) {
           fprintf(stderr, "msgsnd failed\n"); 
           return EXIT_FAILURE;
        }

        if (strncmp(buffer, "end", 3) == 0) {
            running = 0;
        }
    }

    return EXIT_SUCCESS;
}
