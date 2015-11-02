#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

static int alarm_fired = 0;

void ding(int sig) 
{
    alarm_fired = 1;
}

int main(void)
{
    pid_t pid;
    printf("alarm application starting\n");

    pid = fork();

    switch (pid) {
        case -1:
            perror("fork failed");
            break;
        case 0:
            sleep(5);
            kill(getppid(), SIGALRM);
            exit(0);
    }

    printf("waiting for alarm to go off\n");
    (void)signal(SIGALRM, ding);
    pause();
    if (alarm_fired) {
        printf("Ding\n");
    }

    printf("Done\n");

    return EXIT_SUCCESS;
}
