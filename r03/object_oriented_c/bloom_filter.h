#ifndef BLOOM_FILTER_H
#define BLOOM_FILTER_H

#include <stdlib.h>
#include <stdbool.h>

/*
    Define a bloom filter with 3 hashes. For more information on bloom filters
    please refer to https://en.wikipedia.org/wiki/Bloom_filter
*/
typedef struct _bloom_filter {
    /* This will actually hold the set bits */
    unsigned char* bitset;
    unsigned int size;

    void (*add)(struct _bloom_filter* self, char* word);

    bool (*check)(struct _bloom_filter* self, char* word);

    void (*destruct)(struct _bloom_filter* self);
} BloomFilter;


BloomFilter* new_filter(unsigned int size);

#endif /* BLOOM_FILTER_H */
