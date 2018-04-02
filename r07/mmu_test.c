// You can use this file to solidate your understanding of page table.
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void init_root();
unsigned long long get_page_fault_count();
unsigned int translate(unsigned int address);

int main(int argc, char** argv)
{
    init_root();
    while (1) {
        unsigned int address;
        scanf("%X", &address);
        if (address > 0xFFFFFFFF) {
            break;
        }
        printf("%X\n", translate(address));
        printf("============\n");
    }

    return 0;
}
