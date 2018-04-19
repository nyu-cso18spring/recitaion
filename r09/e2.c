#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>

#define LENGTH 1024 * 1024 * 256
#define CORES 4

void vector_op(unsigned long* vector, int begin, int end)
{
    printf("Begin = %d, end = %d\n", begin, end);
    for (int i = begin; i < end; i++) {
        vector[i] *= 3 + 173;
    }
}

void single_core_execution(unsigned long* vector)
{
    struct timeval begin, end;

    gettimeofday(&begin, NULL);
    vector_op(vector, 0, LENGTH);
    gettimeofday(&end, NULL);
    printf("Single core vector_op takes around %.2f seconds\n",
           (end.tv_sec - begin.tv_sec + 
            (end.tv_usec - begin.tv_usec) * 1.0 / 1e6));
}

struct thread_args {
    unsigned long* vector;
    int begin;
    int end;
};

void* vector_op_thread(void* args)
{
    struct thread_args* targs = (struct thread_args*)args;
    vector_op(targs->vector, targs->begin, targs->end);
    return NULL;
}

void multi_core_execution(unsigned long* vector)
{
    struct timeval begin, end;

    gettimeofday(&begin, NULL);
    pthread_t threads[CORES];
    struct thread_args args[CORES];

    // Split the task(data) and create threads to process the split task(data).
    // Hint: You need to read vector_op() first.
    // Hint: You need to use struct thread_args and vector_op_thread() defined above.
    // Hint: You need to use threads and args arrays defined in this function.
    // Hint: "man pthread_create" to understand how to create threads.
    // Hint: You can set the second argument to pthread_create() to NULL.
    int seg_len = LENGTH / CORES;
    for (int i = 0 ; i < CORES; i++) {
        /* FIXME */
    }

    // Wait for the threads to finish.
    // Hint: "man pthread_join" to understand how to wait for some thread to finish.
    // Hint: You can set the second argument to pthread_join() to NULL.
    for (int i = 0 ; i < CORES; i++) {
        /* FIXME */
    }

    gettimeofday(&end, NULL);
    printf("Multi cores vector_op takes around %.2f seconds\n",
           (end.tv_sec - begin.tv_sec + 
            (end.tv_usec - begin.tv_usec) * 1.0 / 1e6));
}

int main(int argc, char** argv)
{
    unsigned long* vector1;
    unsigned long* vector2;
    vector1 = malloc(LENGTH * sizeof(unsigned long));
    vector2 = malloc(LENGTH * sizeof(unsigned long));
    for (int i = 0; i < LENGTH; i++) {
        vector1[i] = i;
        vector2[i] = i;
    }
    single_core_execution(vector1);
    multi_core_execution(vector2);
    for (int i = 0; i < LENGTH; i++) {
        if (vector1[i] != vector2[i]) {
            printf("WRONG IMPLEMENTATION\n");
            return 1;
        }
    }
    printf("CORRECT IMPLEMENTATION\n");
    return 0;
}
