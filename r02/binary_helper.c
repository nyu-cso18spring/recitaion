#include <stdio.h>
#include <stdlib.h>

// Bonus: implement float_to_binary and test it in main


void int_to_binary(int number, char binary[]) {
    int strlen = sizeof(int) * 8;

    for (int i = 0, max = strlen; i < max; i++)
        binary[max - (i + 1)] = (1 << i) & number ? '1' : '0';

    binary[strlen] = '\0';
}


int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Please run with single integer argument to get binary representation\n");
        return 1;
    }

    // atoi mean ascii to integer and is similar to Integer.parseInt(String) in
    // Java.
    int number = atoi(argv[1]);

    // The sizeof function returns the number of bytes and there are 8 bits per
    // byte. We want one character per bit. The extra 1 in size is for the null
    // character to terminate the string.
    char binary[sizeof(int) * 8 + 1];

    // Arrays are pointers so we pass the "string" by reference. 
    int_to_binary(number, binary);
    // Question: Why don't we just create the array in int_to_binary and return
    // it?


    printf("Integer entered: %d\nBinary 0b%s\n", number, binary);
    return 0;
}
