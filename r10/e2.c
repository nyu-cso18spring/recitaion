#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>

#define LENGTH (1024 * 512)

struct thread_args {
    int* data[LENGTH];
    int  producer_index;
    int  consumer_index;
    int  is_done;
};

void consume_data(int* data)
{
    *data = 1;
    free(data);
}

void* consumer(void* args)
{
    struct thread_args* targs = (struct thread_args*)args;
    int next_index = 0;
    while (!targs->is_done) {
        if (targs->producer_index > targs->consumer_index) {
            consume_data(targs->data[targs->producer_index]);
            targs->consumer_index = targs->producer_index;
        }
    }
    return NULL;
}

int* produce_data()
{
    return (int*)malloc(sizeof(int));
}

void* producer(void* args)
{
    // FIXME: Fix the race condition without using pthread_mutex_lock.
    struct thread_args* targs = (struct thread_args*)args;
    for (int i = 0; i < LENGTH; i++) {
        while (targs->consumer_index != targs->producer_index) {;}
        targs->producer_index= i;
        targs->data[i] = produce_data();
    }
    targs->is_done = 1;
    return NULL;
}


int main(int argc, char** argv)
{
    pthread_t p_consumer;
    pthread_t p_producer;
    struct thread_args *args = 
        (struct thread_args*) malloc(sizeof(struct thread_args));
    args->producer_index = -1;
    args->consumer_index = -1;
    args->is_done = 0;

    pthread_create(&p_consumer, NULL, consumer, args);
    pthread_create(&p_producer, NULL, producer, args);
    pthread_join(p_consumer, NULL);
    pthread_join(p_producer, NULL);
    printf("Success\n");
    return 0;
}
