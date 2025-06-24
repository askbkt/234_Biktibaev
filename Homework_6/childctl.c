//
// Created by Аскар on 24.06.2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

int count = 0;
int target = 0;

void handler(int sig) {
    printf("caught: %s\n", strsignal(sig));
    if (sig == target) {
        count++;
    }
}

int main(int argc, char *argv[]){

    int timeout = atoi(argv[1]);
    target = atoi(argv[2]);

    printf("starting. Timeout: %d sec. signalq %d\n", timeout, target);

    for (int i = 3; i < argc; i++){
        int sig = atoi(argv[i]);
        if (signal(sig, handler) == SIG_ERR) {
            perror("signal");
            return 1;
        }
    }

    sleep(timeout);
    printf("timeout passed\n");

    while (count < 3){
        pause();
    }

    printf("got signal %s three times, exxiting\n", strsignal(target));
    return 0;
}
