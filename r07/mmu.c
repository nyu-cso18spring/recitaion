// You are not allowed to modify this file.
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void init_root();
unsigned long long get_page_fault_count();
unsigned int translate(unsigned int address);

int main(int argc, char** argv)
{
    init_root();

    assert(translate(0xFFFF0001) == 0x1FFF0001);
    assert(get_page_fault_count() == 3);
    printf("==========================\n");
    assert(translate(0x5E300109) == 0x7E300109);
    assert(get_page_fault_count() == 6);
    printf("==========================\n");
    assert(translate(0x5E4F0000) == 0x7E4F0000);
    assert(get_page_fault_count() == 7);
    printf("==========================\n");
    assert(translate(0x5E4FF200) == 0x7E4FF200);
    assert(get_page_fault_count() == 7);
    printf("==========================\n");
    assert(translate(0x0) == 0x20000000);
    assert(get_page_fault_count() == 10);
    printf("==========================\n");
    assert(translate(0x1) == 0x20000001);
    assert(get_page_fault_count() == 10);
    printf("==========================\n");
    assert(translate(0xF) == 0x2000000F);
    assert(get_page_fault_count() == 10);
    printf("==========================\n");
    assert(translate(0xFFFFFFFF) == 0x1FFFFFFF);
    assert(get_page_fault_count() == 10);

    return 0;
}
