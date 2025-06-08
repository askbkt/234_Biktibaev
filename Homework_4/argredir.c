//
// Created by Аскар on 08.06.2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <infile> <outfile> <command> [args...]\n", argv[0]);
        return 1;
    }

    char *infile   = argv[1];
    char *outfile  = argv[2];
    char **cmd_argv = &argv[3];

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        int fdin = open(infile, O_RDONLY);
        if (fdin < 0) {
            perror("open infile");
            exit(EXIT_FAILURE);
        }
        if (dup2(fdin, STDIN_FILENO) < 0) {
            perror("dup2 stdin");
            exit(EXIT_FAILURE);
        }
        close(fdin);

        int fdout = open(outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
        if (fdout < 0) {
            perror("open outfile");
            exit(EXIT_FAILURE);
        }
        if (dup2(fdout, STDOUT_FILENO) < 0) {
            perror("dup2 stdout");
            exit(EXIT_FAILURE);
        }
        close(fdout);

        execvp(cmd_argv[0], cmd_argv);
        perror("execvp");
        exit(EXIT_FAILURE);
    }

    int wstatus;
    if (waitpid(pid, &wstatus, 0) < 0) {
        perror("waitpid");
        return 1;
    }

    if (WIFEXITED(wstatus)) {
        printf("%d received\n", WEXITSTATUS(wstatus));
    } else {
        fprintf(stderr, "Child did not exit normally\n");
    }

    return 0;
}