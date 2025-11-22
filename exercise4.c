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
        printf("Child (PID: %d) running...\n", getpid());
        while(1) {
            printf("Child is working...\n");
            sleep(1);
        }
    } else {
        printf("Parent (PID: %d) started child (PID: %d).\n", getpid(), pid);
        sleep(2);

        printf("Parent sending SIGSTOP to pause child...\n");
        kill(pid, SIGSTOP);
        
        printf("Child paused. Waiting 5 seconds (Child should stop printing)...\n");
        sleep(5);

        printf("Parent sending SIGCONT to resume child...\n");
        kill(pid, SIGCONT);
        
        sleep(3);

        printf("Parent killing child to finish...\n");
        kill(pid, SIGKILL);
        wait(NULL);
        printf("Child terminated.\n");
    }

    return 0;
}
