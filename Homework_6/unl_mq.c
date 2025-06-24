//
// Created by Аскар on 24.06.2025.
//
#include <mqueue.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (mq_unlink(argv[1])) {
        perror("mq_unlink");
        return -1;
    }
    return 0;
}
