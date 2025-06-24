//
// Created by Аскар on 24.06.2025.
//
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

void handler(int sig) {
    printf("[caught: %s]\n", strsignal(sig));
}

int main(int argc, char *argv[]){
    int i, count = 0;
    int t = atoi(argv[1]);

    for (i = 2; i < argc; i++){
        int sig = atoi(argv[i]);
        if (signal(sig, handler) == SIG_ERR) {
            perror("signal");
        }
    }

    while(1) {
        printf("%d: %d\n", getpid(), count++);
        sleep(t);
    }
    return 0;
}
