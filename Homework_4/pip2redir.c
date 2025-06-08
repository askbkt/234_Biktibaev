//
// Created by Аскар on 08.06.2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc < 3) return 1;
    int fd[2];
    if (pipe(fd) < 0) exit(1);
    pid_t p1 = fork();
    if (p1 < 0) exit(1);
    if (p1 == 0) {
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]); close(fd[1]);
        execlp(argv[1], argv[1], NULL);
        exit(1);
    }
    pid_t p2 = fork();
    if (p2 < 0) exit(1);
    if (p2 == 0) {
        dup2(fd[0], STDIN_FILENO);
        close(fd[1]); close(fd[0]);
        execvp(argv[2], &argv[2]);
        exit(1);
    }
    close(fd[0]); close(fd[1]);
    int status1, status2;
    waitpid(p1, &status1, 0);
    waitpid(p2, &status2, 0);
    if (WIFEXITED(status1))
        printf("%s exited with status %d\n", argv[1], WEXITSTATUS(status1));
    if (WIFEXITED(status2))
        printf("%s exited with status %d\n", argv[2], WEXITSTATUS(status2));
    return 0;
}