#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define OFFSET_BITS (6)                              // 64 bytes cache line
#define SET_INDEX_BITS (5)                           // 32 sets
#define TAG_BITS (64 - OFFSET_BITS - SET_INDEX_BITS) //
#define NWAYS (8)                                    // 8 ways cache.

void questions()
{
    unsigned answer = 0;
    // Suppose a machine has a n-way set associative cache.
    // The characteristics of the cache are defined in line 5-8.
    //
    // 1) How many bytes of cache does this machine have?
    answer = 0;
    printf("Q1: %u\n", answer);

    // 2) For an address 0x40000100, what is the cache set for the address?
    //    Note that the index for the first set is 0, so the answer should
    //    be a number within 0-31.
    answer = 0;
    printf("Q2: %u\n", answer);

    // 3) For an address 0x4000011F, what is the cache set for the address?
    //    Note that the index for the first set is 0, so the answer should
    //    be a number within 0-31.
    answer = 0;
    printf("Q3: %u\n", answer);

    // 4) Assume that the cache is empty in the begining. After following
    //    addresses are accessed in order, how many cache lines are used
    //    (to store data) in set 0?
    //    0x40000100
    //    0x40000104
    //    0x40000108
    //    0x40000004
    //    0x40000008
    //    0x80000100
    //    0x80000104
    //    0x80000004
    //    0x80000008
    answer = 0;
    printf("Q4: %u\n", answer);
}

int main(int argc, char** argv)
{
    questions();
}
