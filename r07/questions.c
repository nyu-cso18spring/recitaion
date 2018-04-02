#include<stdio.h>

/*
Q1: How many bytes in a physical memory page in this simulator?
*/
void q1(void)
{
    /* Assign the answer of q1 to the answer variable. */
    unsigned answer = 0;
    printf("%u\n", answer);
}

/*
Q2: After line 14 of mmu.c "assert(translate(0xFFFF0001) == 0x1FFF0001);",
    how many bytes are allocated for R0, R1 and R2 page tables?
    Remember that unsigned long long should be viewed as 4 bytes
    (check the comment in the beginning of mmu_lib.c).
*/
void q2(void)
{
    /* Assign the answer of q2 to the answer variable. */
    unsigned answer = 0;
    printf("%u\n", answer);
}

/*
Q3: After line 17 of mmu.c "assert(translate(0x5E300109) == 0x7E300109);",
    how many bytes are allocated for R0, R1 and R2 page tables?
    Remember that unsigned long long should be viewed as 4 bytes
    (check the comment in the beginning of mmu_lib.c).
*/
void q3(void)
{
    /* Assign the answer of q3 to the answer variable. */
    unsigned answer = 0;
    printf("%u\n", answer);
}

/*
Question to think about but no need to submit:
    According to Q2 and Q3, explain why multi-level page table is more memory
    efficient than one-level page table.
*/

int main(int argc, char** argv)
{
    q1();
    q2();
    q3();
}
