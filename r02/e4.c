#include <stdio.h>

// Bonus: Modify this file so that it can take one command line argument and
// use it for variable 'answer'. If the argument is not present, use the hard
// coded value.

int main(int argc, char **argv) {
    // FIXME: Modify the value of answer so that the output in the end is 39661568.
    unsigned answer = 1337;

    // DO NOT modify following lines.
    answer = (answer >> 5) << 6;
    printf("%u\n", answer);
}
