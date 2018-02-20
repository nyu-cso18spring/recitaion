#include "bloom_filter.h"

// See following for primes: https://en.wikipedia.org/wiki/List_of_prime_numbers
struct bit_trio {
    unsigned long first;
    unsigned long second;
    unsigned long third;
};

// Hacky hash function that returns three hash value for a null terminated
// string.
struct bit_trio hash(char* word) {
    unsigned long seeds[] = {1597, 28657,  514229};

    while (*word) {
        for (int i = 0; i < 3; i++) {
            seeds[i] = (((seeds[i] * 2971215073) ^ (*word << 11)) + 433494437)
                % 18446744073709551557lu;
        }
        word += 1;
    }

    return (struct bit_trio) {seeds[0], seeds[1], seeds[2]};
}

const int byte_mask[] = {
    0x01,
    0x02,
    0x04,
    0x08,
    0x10,
    0x20,
    0x40,
    0x80,
};

// Add function for bloom filter. For each hash value, index into the bitset
// and perform bitwise or with correct mask to make sure it is set.
void _add(struct _bloom_filter* self, char* word) {
    struct bit_trio h = hash(word);
    unsigned long* hashes = (unsigned long*) &h;

    for (int i = 0; i < 3; i++) {
        unsigned int index = hashes[i] % self->size;

        self->bitset[index / 8] |= byte_mask[index % 8];
    }
}


// Check function for bloom filter. For each hash value, index into the bitset
// and return false if that bit was not set. If all were set you hit the return
// true statement at end.
bool _check(struct _bloom_filter* self, char* word) {
    struct bit_trio h = hash(word);
    unsigned long* hashes = (unsigned long*) &h;

    for (int i = 0; i < 3; i++) {
        unsigned int index = hashes[i] % self->size;

        unsigned char byte = self->bitset[index / 8];
        bool is_set = byte & byte_mask[index % 8];
        
        if (!is_set)
            return false;
    }

    return true;
}

// Free memory for self destruct.
// Note, this is a little dangerous as the pointer passed as argument not points
// to freed memory.
void _destruct(struct _bloom_filter* self) {
    free(self->bitset);
    free(self);
}


// Allocate memory and assign function pointers.
BloomFilter* new_filter(unsigned int size) {
    unsigned int byte_size = (size + 7) / 8;

    BloomFilter* bf = (BloomFilter*) calloc(1, sizeof(BloomFilter));
    bf->bitset = (unsigned char*) calloc(byte_size, sizeof(char));
    bf->size = byte_size * 8;
    bf->add = _add;
    bf->check = _check;
    bf->destruct = _destruct;

    return bf;
}
