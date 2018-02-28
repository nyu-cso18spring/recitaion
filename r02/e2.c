#include <stdio.h>

int main(int argc, char **argv) {
    // FIXME: Modify the values of i and j so that the output in the end is -28.
    int i = 0;
    int j = 7;

    // DO NOT modify following lines.
    float array[] = {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7};
    unsigned p1 = (unsigned)(&array[i]);
    unsigned p2 = (unsigned)(&array[j]);
    int answer = p1 - p2;

    printf("%d\n", (p1 - p2));
}
