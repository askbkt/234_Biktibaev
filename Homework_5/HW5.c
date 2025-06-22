//
// Created by Аскар on 22.06.2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

int *arr;
int n;
int sum = 0;

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

int start1, end1, start2, end2, start3, end3, start4, end4;

void *threadFunct(void *arg){
    int i;
    int *range = (int *)arg;
    int local_sum = 0;

    for (i = range[0]; i < range[1]; i++){
        local_sum += arr[i];
    }

    pthread_mutex_lock(&mtx);
    sum += local_sum;
    pthread_mutex_unlock(&mtx);

    return NULL;
}

int main(){

    // 1
    printf("unput numb n: ");
    scanf("%d", &n);
    printf("Ok, %d\n", n);

    // 2
    arr = (int *)malloc(n * sizeof(int));
    srand(time(NULL));

    for (int i = 0; i < n; i++){
        arr[i] = rand() % 100;
    }

    printf("arr: ");
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 3
    int base = n / 4;
    int rem = n % 4;

    start1 = 0;
    end1 = start1 + base + (rem > 0 ? 1 : 0);

    start2 = end1;
    end2 = start2 + base + (rem > 1 ? 1 : 0);

    start3 = end2;
    end3 = start3 + base + (rem > 2 ? 1 : 0);

    start4 = end3;
    end4 = n;

    // 4 & 5
    int args1[2] = {start1, end1};
    int args2[2] = {start2, end2};
    int args3[2] = {start3, end3};
    int args4[2] = {start4, end4};

    pthread_t t1, t2, t3, t4;

    pthread_create(&t1, NULL, threadFunct, args1);
    pthread_create(&t2, NULL, threadFunct, args2);
    pthread_create(&t3, NULL, threadFunct, args3);
    pthread_create(&t4, NULL, threadFunct, args4);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);

    printf("res sum: %d\n", sum);

    free(arr);

    return 0;
}
