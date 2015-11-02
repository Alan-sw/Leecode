/*
 * =====================================================================================
 *
 *       Filename:  shm1.c
 *
 *    Description: client
 *
 *        Created:  10/14/2015 04:23:39 PM
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
    int shmid;

    srand((unsigned int)getpid());

    shmid = shmget((key_t)1234, sizeof(struct shared_use_st), 0666 | IPC_CREAT);
    if (shmid == -1) {
        fprintf(stderr, "shmget failed\n");
        return EXIT_FAILURE;
    }

    shared_memory = shmat(shmid, (void*)0, 0);
    if (shared_memory == (void*) -1) {
        fprintf(stderr, "shmat failed\n");
        return EXIT_FAILURE;
    }

    printf("Memory attached at with %%p : %p\n", shared_memory);
    printf("Memory attached at with %%X : %X\n", (int)shared_memory);

    shared_stuff = (struct shared_use_st *)shared_memory;
    shared_stuff->written_by_you = 0;
    while (running) {
        if (shared_stuff->written_by_you) {
            printf("You wrote: %s", shared_stuff->some_text);
            sleep(rand() % 4);
            shared_stuff->written_by_you = 0;
            if (strncmp(shared_stuff->some_text, "end", 3) == 0) {
                running = 0;
            }
        }
    }
    
    if (shmdt(shared_memory) == -1) {
        fprintf(stderr, "shmdt failed\n");
        return EXIT_FAILURE;
    }

    if (shmctl(shmid, IPC_RMID, 0) == -1) {
        fprintf(stderr, "shmctl(IPC_RMID) failed\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}


