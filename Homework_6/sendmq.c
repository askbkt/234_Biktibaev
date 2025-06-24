//
// Created by Аскар on 24.06.2025.
//
#include <mqueue.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    mqd_t mqd;
    unsigned int prio = 1;

    mqd = mq_open(argv[1], O_WRONLY);
    mq_send(mqd, argv[2], strlen(argv[2]), prio);

    return 0;
}
