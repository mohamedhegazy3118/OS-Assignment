#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        printf("Child process (PID: %d) running in background. Sleeping for 10 seconds...\n", getpid());
        sleep(10);
        printf("Child process finished.\n");
    } else {
        printf("Parent process (PID: %d) started child (PID: %d).\n", getpid(), pid);
        printf("Parent exiting, leaving child running in background.\n");
    }

    return 0;
}
