/* halamadrid.c */
#include <stdio.h>

void fred(void);
double john(double);
void bill(void);
double sam(double);

int main() {
    puts("→ calling fred()");
    fred();

    puts("→ calling john(0.5)");
    double j = john(0.5);
    printf(" john returned %.3f\n\n", j);

    puts("→ calling bill()");
    bill();

    puts("→ calling sam(0.5)");
    double s = sam(0.5);
    printf(" sam returned %.3f\n", s);

    return 0;
}//
// Created by Аскар on 05.05.2025.
//
