#include <stdio.h>

void bill(void) {
    printf("[load-time interpose] bill is called\n");
}

double sam(double x) {
    printf("[load-time interpose] sam(%.3f) is called\n", x);
    return 999.0;
}//
// Created by Аскар on 05.05.2025.
//
