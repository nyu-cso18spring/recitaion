#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define INCR 1000
#define THRD 4

void* run(void* data) {
    int* x = (int*) data;
    for (int i = 0; i < INCR; i++)
        *x += 1;
    return NULL;
}


int main() {
    pthread_t thrds[THRD];
    int x = 0;
    for (int i = 0; i < THRD; i++)
        pthread_create(&thrds[i], NULL, run, (void*) &x);

    for (int i = 0; i < THRD; i++)
        pthread_join(thrds[i], NULL);
    printf("Value of x is %d, should be %d\n", x, INCR * THRD);
    return 0;
}
