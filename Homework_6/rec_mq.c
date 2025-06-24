//
// Created by Аскар on 24.06.2025.
//
#include <mqueue.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    mqd_t mqd;
    unsigned int prio;
    void *buf;
    struct mq_attr attr;
    ssize_t n;

    mqd = mq_open(argv[1], O_RDONLY);
    mq_getattr(mqd, &attr);
    buf = malloc(attr.mq_msgsize);

    n = mq_receive(mqd, buf, attr.mq_msgsize, &prio);
    printf("Read %ld bytes; priority = %u\n", (long)n, prio);

    free(buf);
    return 0;
}
