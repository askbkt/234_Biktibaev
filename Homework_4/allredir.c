//
// Created by Аскар on 08.06.2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <command> <infile> <outfile>\n", argv[0]);
        return 1;
    }

    char *cmd    = argv[1];
    char *infile = argv[2];
    char *outfile= argv[3];

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {

        int in_fd = open(infile, O_RDONLY);
        if (in_fd < 0) {
            perror("open infile");
            exit(EXIT_FAILURE);
        }
        if (dup2(in_fd, STDIN_FILENO) < 0) {
            perror("dup2 stdin");
            exit(EXIT_FAILURE);
        }
        close(in_fd);


        int out_fd = open(outfile, O_CREAT|O_WRONLY|O_TRUNC, 0644);
        if (out_fd < 0) {
            perror("open outfile");
            exit(EXIT_FAILURE);
        }
        if (dup2(out_fd, STDOUT_FILENO) < 0) {
            perror("dup2 stdout");
            exit(EXIT_FAILURE);
        }
        close(out_fd);


        execlp(cmd, cmd, (char*)NULL);

        perror("execlp");
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
        printf("Child did not exit normally\n");
    }

    return 0;
}