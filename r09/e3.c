#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define SIZE 100

int count = 1;

void* add_to(void* arg) {
    int* nums = (int*) arg;

    for (int i = 0; i < SIZE; i++) {
        if (nums[i] == 0) {
            nums[i] = count;
            count++;
        }
    }
}

int main() {
    int* numbers = (int*) calloc(SIZE, sizeof(int));

    pthread_t t1, t2;

    pthread_create(&t1, NULL, add_to, numbers);
    pthread_create(&t2, NULL, add_to, numbers);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // Check for consistency 
    int last = 0;
    for (int i = 0; i < SIZE; i++) {
        if (numbers[i] <= last) {
            printf("Found that %d came after %d\n", numbers[i], last);
            return 1;
        }
        last = numbers[i];
    }
    return 0;
}
