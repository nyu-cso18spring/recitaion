#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Write a (probably) 32 bit number character array
void int_to_binary(int number, char binary[]) {
    int strlen = sizeof(int) * 8;

    // String are indexed from right to left, but binary numbers usually have
    // the least significant bit (the smallest valued bit) on the right and get
    // bigger going left.
    for (int i = 0, max = strlen; i < max; i++)
        binary[max - (i + 1)] = (1 << i) & number ? '1' : '0';

    binary[strlen] = '\0';
}

// Parse a binary string to get actual number
int binary_to_int(char binary[]) {
    int number = 0;

    // See comment int int_to_binary  about string indexes compared to binary
    // numbers
    for (int i = 0; binary[i]; i++) {
        number = number << 1;
        if (binary[i] == '1')
            number = number | 1;
    }

    return number;
}


int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Please run with single integer or binary (must have '0b' prefix) argument\n");
        return 1;
    }

    // The sizeof function returns the number of bytes and there are 8 bits per
    // byte. We want one character per bit. The extra 1 in size is for the null
    // character to terminate the string.
    char binary[sizeof(int) * 8 + 1];
    int number;

    if (strlen(argv[1]) > 2 && strncmp(argv[1], "0b", 2) == 0) {
        // A binary number was entered

        // Copy the binary string to binary, removing the leading '0b'
        strcpy(binary, argv[1] + 2);
        number = binary_to_int(binary);

    } else {
        // atoi mean ascii to integer and is similar to Integer.parseInt(String) in
        // Java.
        number = atoi(argv[1]);

        // Arrays are pointers so we pass the "string" by reference. 
        int_to_binary(number, binary);
        // Question: Why don't we just create the array in int_to_binary and return
        // it?
    }

    printf("Integer %d\nBinary 0b%s\n", number, binary);
    return 0;
}
