#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        printf("Child process (PID: %d) started. Sleeping...\n", getpid());
        sleep(300);
    } else {
        printf("Parent process (PID: %d) started child (PID: %d).\n", getpid(), pid);
        sleep(2);

        printf("Parent sending SIGKILL to child (PID: %d)...\n", pid);
        if (kill(pid, SIGKILL) == 0) {
            printf("Signal sent successfully.\n");
        } else {
            perror("Failed to send signal");
        }

        wait(NULL);
        printf("Child process terminated.\n");
    }

    return 0;
}
