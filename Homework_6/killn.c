//
// Created by Аскар on 24.06.2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    int pid, sig;

    if (argc != 3){
        printf("usage %s pid sig name\n", argv[0]);
        return 1;
    }

    pid = atoi(argv[1]);

    if (strcmp(argv[2], "INT") == 0) sig = SIGINT;
    else if (strcmp(argv[2], "TERM") == 0) sig = SIGTERM;
    else if (strcmp(argv[2], "STOP") == 0) sig = SIGSTOP;
    else if (strcmp(argv[2], "CONT") == 0) sig = SIGCONT;
    else {
        printf("no such signal\n");
        return 1;
    }

    if (kill(pid, sig) == -1) {
        perror("kill");
        return 1;
    }

    return 0;
}
