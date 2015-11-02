#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>

void *thread_function(void *arg);

#define WORK_SIZE 1024

sem_t bin_sem;
char work_area[WORK_SIZE];

int main(void)
{
    int res;
    pthread_t a_thread;
    void *thread_result;

    res = sem_init(&bin_sem, 0, 0);
    if (res != 0) {
        perror("Semaphore initialization failed");
        return EXIT_FAILURE;
    }
    res = pthread_create(&a_thread, NULL, thread_function, NULL);
    if (res != 0) {
        perror("Thread creation failed");
        return EXIT_FAILURE;
    }
    
    printf("Input somet text. Enter 'end' to finish\n");
    while (strncmp("end", work_area, 3) != 0) {
        if (strncmp(work_area, "FAST", 4) == 0) {
            printf("============first post============\n");
            sem_post(&bin_sem);
            strcpy(work_area, "wheeee...");
        } else {
            fgets(work_area, WORK_SIZE, stdin);
            printf("------I'm goint to post the semaphore------\n");
        }
        printf("============second post============\n");
        sem_post(&bin_sem);
    }
    printf("\nWaitng for thread to finish...\n");
    res = pthread_join(a_thread, &thread_result);
    if (res != 0) {
        perror("Thread join failed");
        return EXIT_FAILURE;
    }
    printf("Thread joined\n");
    sem_destroy(&bin_sem);

    return EXIT_SUCCESS;
}

void *thread_function(void *arg)
{
    printf("\nI'm waiting............\n");
    sem_wait(&bin_sem);
    while (strncmp("end", work_area, 3) != 0) {
        printf("You input %d character\n", (int)(strlen(work_area) - 1));
        printf("\nI'm waiting............\n");
        sem_wait(&bin_sem);
    }

    pthread_exit(NULL);
}



















