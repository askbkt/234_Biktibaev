//
// Created by Аскар on 08.06.2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    pid_t pid1 = fork();
    if (pid1 < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid1 > 0) {

        waitpid(pid1, NULL, 0);
        printf("Hello from Parent (pid=%d)\n", getpid());
    }
    else {

        pid_t pid2 = fork();
        if (pid2 < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid2 > 0) {

            waitpid(pid2, NULL, 0);
            printf("Hello from Child (pid=%d, parent=%d)\n",
                   getpid(), getppid());
        }
        else {

            printf("Hello from Grandchild (pid=%d, parent=%d)\n",
                   getpid(), getppid());
        }
        exit(EXIT_SUCCESS);
    }

    return 0;
}