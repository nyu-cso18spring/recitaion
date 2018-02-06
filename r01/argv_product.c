#include <stdio.h>
#include <stdlib.h>

// This simply defines the usage of product so main know about it when the
// compiler reaches main, but before we define product.
int product(int length, int numbers[]);


int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Please provide at least one number for product\n");
        return 1;
    }
    
    int length = argc - 1;
    int numbers[length];
    for (int i = 1; i < argc; i++) {
        int number = atoi(argv[i]);
        numbers[i - 1] = number;
        printf("Adding %d to array\n", number);
    }

    int prod = product(length, numbers);
    printf("The product of command line arguments is %d.\n", prod);
    
    return 0;
}


int product(int length, int numbers[]) {
    int prod = 1;
    for (int i = 0; i < length; i++)
        prod = prod * numbers[i];

    return prod;
}
