//
// Created by Аскар on 24.06.2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    int i = 0;
    int t = atoi(argv[1]);

    while(1) {
        printf("%d: %d\n", getpid(), i++);
        sleep(t);
    }
    return 0;
}
