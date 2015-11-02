/*
 * =====================================================================================
 *
 *       Filename:  shm2.c
 *
 *    Description:  server
 *
 *        Created:  10/14/2015 04:32:09 PM
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
#include <sys/shm.h>

#include "shm_com.h"

int main(void)
{
    int running = 1;
    void *shared_memory = (void *)0;
    struct shared_use_st *shared_stuff;
    char buffer[BUFSIZ];
    int shmid;

    shmid = shmget((key_t)1234, sizeof(struct shared_use_st), 0666 | IPC_CREAT);
    if (shmid == -1) {
        fprintf(stderr, "shmget failed\n");
        return EXIT_FAILURE;
    }

    shared_memory = shmat(shmid, (void*)0, 0);
    if (shared_memory == (void*)-1) {
        fprintf(stderr, "shtmat failed\n");
        return EXIT_FAILURE;
    }

    printf("Memory attached at with %%p : %p\n", shared_memory);
    printf("Memory attached at with %%X : %X\n", (int)shared_memory);

    shared_stuff = (struct shared_use_st *)shared_memory;
    while (running) {
        while (shared_stuff->written_by_you == 1) {
            sleep(1);
            printf("waiting for client...\n");
        }
        printf("Enter some text : \n");
        fgets(buffer, BUFSIZ, stdin);

        strncpy(shared_stuff->some_text, buffer, TEXT_SZ);
        shared_stuff->written_by_you = 1;
        if (strncmp(buffer, "end", 3) == 0) {
            running = 0;
        }
    }

    if (shmdt(shared_memory) == -1) {
        fprintf(stderr, "shmdt failed\n");
        return EXIT_FAILURE;
        
    }

    return EXIT_SUCCESS;
}
