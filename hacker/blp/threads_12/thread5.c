#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread_fucntion(void *arg);

char message[] = "Hello World";
int thread_finished = 0;

int main(void)
{
    int res;
    pthread_t a_thread;
    pthread_attr_t thread_attr;

    res = pthread_attr_init(&thread_attr);
    if (res != 0) {
        perror("Attribute creation failed");
        return EXIT_FAILURE;
    }

    res = pthread_attr_setdetachstate(&thread_attr, PTHREAD_CREATE_DETACHED);
    if (res != 0) {
        perror("Setting detached attribute failed");
        return EXIT_FAILURE;
    }

    res = pthread_create(&a_thread, &thread_attr, thread_fucntion, (void *)message);
    if (res != 0) {
        perror("Thread creation failed");
        return EXIT_FAILURE;
    }
   
    (void)pthread_attr_destroy(&thread_attr);

    while (!thread_finished) {
        printf("Waiting for thread to say it's finished...\n");
        sleep(1);
    }
    
    printf("Other thread finished ------- Bye\n");

    return EXIT_SUCCESS;
}

void *thread_fucntion(void *arg)
{
    printf("thread_fucntion is runnig. Argument was %s\n", (char*)arg);
    sleep(4);
    printf("Second thread setting finish flag, and exiting now\n");
    thread_finished = 1;
    pthread_exit(NULL);

    printf("-------------------should not disapper---------------------------\n");
}










