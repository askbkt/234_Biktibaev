#include <stdio.h>


void __real_fred(void);
double __real_john(double);


void __wrap_fred(void) {
    printf("[link-time interpose] fred is called\n");
    __real_fred();
}

double __wrap_john(double x) {
    printf("[link-time interpose] john(%.3f) is called\n", x);
    return __real_john(x);
}//
// Created by Аскар on 05.05.2025.
//
