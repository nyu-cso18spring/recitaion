#include <stdio.h>

int main(int argc, char **argv) {
    // FIXME: Modify the value of answer so that the output in the end is 1069547520.
    float answer = 42;

    // DO NOT modify following lines.
    unsigned* unsigned_ptr = (unsigned*)(&answer);
    printf("%u\n", *unsigned_ptr);
}
