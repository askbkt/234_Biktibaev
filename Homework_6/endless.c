//
// Created by Аскар on 24.06.2025.
//
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int i;
    for (i = 0; ; i++){
        sleep(1);
        printf("%d/n", i);
    }
    return 0;

}
