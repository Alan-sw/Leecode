#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

void *thread_function(void *arg);

char message[] = "Hello World";

int main(void)
{
    int res;
    pthread_t a_thread;
    void *thread_result;

    res = pthread_create(&a_thread, NULL, thread_function, (void*)message);
    if (res != 0) {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Waiting for thread to finish...\n");
    
    res = pthread_join(a_thread, &thread_result);
    if (res != 0) {
        perror("Thread join failed");
        exit(EXIT_FAILURE);
    }

    printf("Thread joined, it returned %s\n", (char*)thread_result);
    printf("Message is now %s\n", message);
    
    return EXIT_SUCCESS;
}

void *thread_function(void *arg)
{
    printf("thread_function is running. Argument was %s\n", (char*)arg); 
    sleep(3);
    strcpy(message, "bye!");
    pthread_exit("Thank you for the CPU time");
}
