#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread_function(void *arg);

int main(void)
{
    int res;
    pthread_t a_thread;
    void *thread_result;

    res = pthread_create(&a_thread, NULL, thread_function, NULL);
    if (res != 0) {
        perror("Thread creation failed");
        return EXIT_FAILURE;
    }
    
    sleep(3);
    printf("Canceling thread... \n");
    res = pthread_cancel(a_thread);
    if (res != 0) {
        perror("Thread cancelation failed");
        return EXIT_FAILURE;
    }

    printf("Waiting for thread to finish...\n");
    res = pthread_join(a_thread, &thread_result);
    if (res != 0) {
        perror("thread join failed");
        return EXIT_FAILURE;
    }
    printf("main is still running\n");

    return EXIT_SUCCESS;
}

void *thread_function(void *arg)
{
    int i, res;
    res = pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    if (res != 0) {
        perror("thread pthread_setcancelstate failed");
        exit(EXIT_FAILURE);
    }

    res = pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);
    if (res != 0) {
        perror("thread pthread_setcanceltype failed");
        exit(EXIT_FAILURE);
    }

    printf("thread_function is still running\n");
    for (i = 0; i < 10; ++i) {
        printf("thread is still running (%d)......\n", i);
        sleep(1);
    }
    printf("I'am still running\n");
    pthread_exit(0);
}
